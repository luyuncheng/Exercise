//////
////// Created by 鲁蕴铖 on 16/6/25.
//////
////
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <time.h>
//#define SERVER_PORT 8888
//#define BUFFER_SIZE 1024
//#define FILE_NAME_MAX_SIZE 512
//
//int main()
//{
//    while(1) {
//        printf("input serveraddress");
//        char svradr[BUFFER_SIZE];
//        scanf("%s",svradr);
//
//        // client_addr
//        struct sockaddr_in client_addr;
//        bzero(&client_addr, sizeof(client_addr));
//        client_addr.sin_family = AF_INET;
//        client_addr.sin_addr.s_addr = htons(INADDR_ANY); // auto get local address
//        client_addr.sin_port = htons(0); //auto allocated port by os
//
//        //socket
//        int client_socket = socket(AF_INET, SOCK_STREAM, 0);
//        if(client_socket < 0) {
//            printf("Create Socket Failed!\n");
//            exit(1);
//        }
//
//        // bind
//        if( bind(client_socket, (struct sockaddr *)&client_addr, sizeof(client_addr)) ) {
//            printf("Client Bind Port Failed\n");
//            exit(1);
//        }
//
//        //server
//        struct sockaddr_in server_addr;
//        bzero(&server_addr, sizeof(server_addr));
//        server_addr.sin_family = AF_INET;
//
//        if( inet_aton(svradr, &server_addr.sin_addr) == 0) {
//            printf("Server ip address error!\n");
//            exit(1);
//        }
//
//        server_addr.sin_port = htons(SERVER_PORT);
//        socklen_t server_addr_length = sizeof(server_addr);
//
//        //Connect
//        if( connect(client_socket, (struct sockaddr *)&server_addr, server_addr_length) < 0) {
//            printf("can not connect to %s!\n",svradr);
//            exit(1);
//        }
//
//        char file_name[FILE_NAME_MAX_SIZE];
//        bzero(file_name, sizeof(file_name));
//        printf("Input file name on server\n");
//        scanf("%s",file_name);
//        printf("file name = %s\n",file_name);
//        char buffer[BUFFER_SIZE];
//        bzero(buffer, sizeof(buffer));
//        strncpy(buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));
//        // send file name
//        send(client_socket, buffer, BUFFER_SIZE, 0);
//
//        FILE *fp = fopen(file_name, "w");
//        if( fp == NULL ) {
//            printf("File:\t %s Can not open to write !\n",file_name);
//            exit(1);
//        }
//
//        bzero(buffer,sizeof(buffer));
//        int length = 0;
//        unsigned long starttime = clock();
//// recv
//        while(length =recv(client_socket, buffer, BUFFER_SIZE, 0)) {
//            if(length < 0) {
//                printf("client receive data from server failed\n");
//                break;
//            }
////              printf("get a byte\n");
//            int write_length = fwrite(buffer, sizeof(char), length, fp);
//            if(write_length < length) {
//                printf("file write failed\n");
//                break;
//            }
//            bzero(buffer,BUFFER_SIZE);
//        }
//        unsigned long endtime = clock();
//        printf("spend time :%lf\n",((double)(endtime-starttime))/CLOCKS_PER_SEC);
//        printf("recive file finish\n");
//
//        fclose(fp);
//        close(client_socket);
//        char cmd[1024];
//        sprintf(cmd,"md5sum %s > %s.md5",file_name,file_name);
//        printf("cmd:%s\n",cmd);
//        system(cmd);
//        bzero(&cmd,sizeof(cmd));
//        sprintf(cmd,"cat %s.md5",file_name);
//        system(cmd);
//    }
//}
