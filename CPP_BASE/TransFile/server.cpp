////
//// Created by 鲁蕴铖 on 16/6/25.
////
//
//#include <netinet/in.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//
//#define SERVER_PORT 8888
//#define LENGTH_OF_LISTEN_QUEUE 20
//#define BUFFER_SIZE 1024+10
//#define FILE_NAME_MAX_SIZE 512
//
//
//
//int main()
//{
//    // init
//    struct sockaddr_in server_addr;
//    bzero(&server_addr, sizeof(server_addr));
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
//    server_addr.sin_port = htons(SERVER_PORT);
//
//    //create a stream socket
//    int server_sock= socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
//    if(server_sock < 0){
//        printf("Create Socket Failed\n");
//        exit(1);
//    }
//
//    // bind
//    if( bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) <0 ) {
//        printf("Server Bind Port:%d Failed!\n",SERVER_PORT);
//        exit(1);
//    }
//
//    //listen
//    if( listen(server_sock, LENGTH_OF_LISTEN_QUEUE)) {
//        printf("Server Listen Failed! \n");
//        exit(1);
//    }
//
//    // run
//    while(1) {
//        // client sockaddr
//        struct sockaddr_in client_addr;
//        socklen_t  len = sizeof(client_addr);
//
//        // block function
//        int accept_socket = accept(server_sock, (struct sockaddr *)&client_addr, &len);
//        if(accept_socket < 0) {
//            printf("Server Accept Failed!\n");
//            break;
//        }
//
//        // receive buffer
//        char buffer[BUFFER_SIZE];
//        bzero(buffer, sizeof(buffer));
//        int length = recv(accept_socket, buffer, BUFFER_SIZE, 0);
//        if(length < 0) {
//            printf("Server Receive data failed\n");
//            break;
//        }
//
//
//        char file_name[FILE_NAME_MAX_SIZE+1];
//        bzero(file_name, sizeof(file_name));
//        strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
//
//        FILE *fp = fopen(file_name, "r");
//        if(fp != NULL){
//
//            bzero(buffer, BUFFER_SIZE);
//            int file_block_length = 0;
//            while( (file_block_length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
//                //printf("file_block_length = %d \n", file_block_length);
//                if(send(accept_socket, buffer, file_block_length, 0) < 0) {
//                    printf("send file:\t%s Failed\n",file_name);
//                    break;
//                }
//                bzero(buffer, sizeof(buffer));
//            }
//            fclose(fp);
//            printf("File:\t%s Transfer Finished!\n", file_name);
//
//        } else {
//            printf("File:\t%s Not Found! \n",file_name);
//        }
//        close(accept_socket);
//    }
//
//}