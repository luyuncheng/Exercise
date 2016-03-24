//
// Created by 鲁蕴铖 on 16/3/24.
//


#include <sys/socket.h>
#include <sys/event.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define exit_if(r,...) if(r) {print(__VA_ARGS__);printf("error no : %d error msg %s \n",errno,strerror(errno));exit(1);}

const int kReadEvent = 1;
const int kWriteEvent = 2;

void setNonBlock(int fd) {
//    获取文件状态标志
    int flags =fcntl(fd,F_GETFL,0);
    exit_if(flags<0,"fcntl failed\n");
//    设置fd为非阻塞模式
    int r = fcntl(fd,F_SETFL,flags | O_NONBLOCK);
    exit_if(r<0,"fcntl failed\n");
}

void updateEvents(int efd, int fd, int events, bool modify)
{
    struct kevent ev[20];
    int n = 0;
    if (events & kReadEvent) {
        // 将事件ev[n] 设置fd的文件描述符,事件过滤器为读事件,行为标识为添加事件,标识值和过滤器数据为0,用来传数据的fd
        EV_SET(&ev[n++], fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, (void *)(intptr_t)fd);
    } else if(modify) {
        // 将事件ev[n] 设置fd的文件描述符,事件过滤器为删事件,行为标识为添加事件,标识值和过滤器数据为0,用来传数据的fd
        EV_SET(&ev[n++], fd, EVFILT_READ, EV_DELETE, 0, 0, (void *)(intptr_t)fd);
    }

    if(events & kWriteEvent) {
        EV_SET(&ev[n++], fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, (void *)(intptr_t)fd);
    } else if(modify) {
        EV_SET(&ev[n++], fd, EVFILT_WRITE, EV_DELETE, 0, 0, (void *)(intptr_t)fd);
    }

    printf("%s fd %d events read %d write %d \n",
            modify? "mod":"add", fd, events & kReadEvent, events & kWriteEvent);

//    第一个参数返回的唯一标识符, 要对ev的时间集合操作,n为需要修改的个数
    int r = kevent(efd, ev, n, NULL, 0, NULL);

    exit_if(r,"kevent failed");

}

void handlerAccept(int efd, int fd) {
    struct sockaddr_in raddr;
    socklen_t rsz = sizeof(raddr);
    int cfd = accept(fd, (struct sockaddr *)&raddr, &rsz);
    exit_if(cfd<0, "accept failed");
    sockaddr_in peer,local;
    socklen_t alen = sizeof(peer);
//    已经和对等方连接,次函数用来找到对方的地址
    int r = getpeername(cfd, (sockaddr*)&peer, &alen);
    exit_if(r<0, "getpeername failed");
    printf("accept a connection from %s \n",inet_ntoa(raddr.sin_addr));
    setNonBlock(cfd);
    updateEvents(efd, cfd, kReadEvent | kWriteEvent, false);
}

const int bufsize = 4096;

void handleRead(int efd, int fd) {
    char buf[bufsize];
    int n = 0;
    while((n = read(fd,buf, sizeof(buf))) > 0) {
        printf("read %d bytes\n",n);
        int r = write(fd,buf,n);// 写出读取得数据
        //实际应用中，写出数据可能会返回EAGAIN，此时应当监听可写事件，当可写时再把数据写出
        exit_if(r<=0,"write error");
    }
    if(n<0 && (errno == EAGAIN || errno == EWOULDBLOCK))
        return;
    //实际应用中，n<0应当检查各类错误，如EINTR
    exit_if(n<0,"read error");
    close(fd);
    printf("fd %d closed\n",fd);
}

void handleWrite(int efd, int fd) {
//实际应用应当实现可写时写出数据，无数据可写才关闭可写事件
    updateEvents(efd, fd, kReadEvent, true);
}

void loop_once (int efd, int lfd, int waitms) {
    struct timespec timeout;
    timeout.tv_sec = waitms / 1000;
    timeout.tv_nsec = (waitms % 1000) * 1000 * 1000;
    const int kMaxEvent = 20;
    struct kevent activeEvs[kMaxEvent];
    int n = kevent(efd, NULL, 0, activeEvs, kMaxEvent, &timeout);
    printf("kqueue_wait return %d\n", n);
    for(int i = 0; i < n; i++) {
        int fd = (int)(intptr_t)activeEvs[i].udata;
        int events = activeEvs[i].filter;
        if(events == EVFILT_READ) {
            if(fd == lfd) {
                handlerAccept(efd,fd);
            } else {
                handleRead(efd,fd);
            }
        } else if(events == EVFILT_WRITE) {
            handleWrite(efd,fd);
        } else {
            exit_if(1,"unknow event");
        }
    }
}
int main()
{
    int port = 99;
    int epollfd = kqueue();
    exit_if(epollfd<0, "epoll_create failed");

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    exit_if(listenfd<0, "socket failed");
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htonl(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    int r = bind(listenfd,(struct sockaddr *)&addr, sizeof(struct sockaddr));
    exit_if(r,"bind to 0.0.0.0:%d failed %d %s",port,errno,strerror(errno));
    printf("fd %d listening at %d \n",listenfd,port);
    setNonBlock(listenfd);
    updateEvents(epollfd,listenfd,kReadEvent,false);
    //实际应用应当注册信号处理函数，退出时清理资源
    for(;;) {
        loop_once(epollfd,listenfd,10000);
    }
    return 0;
}