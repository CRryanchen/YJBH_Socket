
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>

#define PORT                2333     /**< 监听端口 */
#define BACKLOG             5      /**< 最大监听数 */

int main(int argc, char * argv[])
{
    int socketFd = 0;               // socket文件描述符
    int connectFd = 0;              // 建立连接后的文件描述符
    int recvLen = 0;                // 接收信息的返回值
    int ret = 0;

    char buf[4096];
    struct sockaddr_in localAddr = {0}; // 本地地址信息
    struct sockaddr_in remoteAddr = {0};    // 对方地址信息
    socklen_t socklen = 0;

    socketFd = socket(AF_INET, SOCK_STREAM, 0); // 建立socket
    if (socketFd < 0)
    {
        perror("socket");
        exit(0);
    }

    printf("创建套接字成功\n");

    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(PORT);   // 端口号
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);   // 监听地址
    // localAddr.sin_addr.s_addr = inet_addr("192.168.0.108");

    // 绑定地址结构体和socket
    ret = bind(socketFd, (const struct sockaddr *)&localAddr, sizeof(localAddr));
    if (ret < 0)
    {
        perror("bind");
        exit(0);
    }

    printf("绑定地址成功\n");
    
    // 开启监听，第二个参数是最大监听数
    ret = 0;
    ret = listen(socketFd, BACKLOG);
    if (ret < 0)
    {
        perror("listen");
        exit(0);
    }

    printf("监听成功\n");
    
    // 阻塞直到有连接
    connectFd = accept(socketFd, (struct sockaddr *)&remoteAddr, &sizeof(remoteAddr));
    if (connectFd < 0)
    {
        perror("accept");
        exit(0);
    }
    else
    {
        printf("有设备接入");
        printf("Client from %s:%d \n",inet_ntoa(*(struct in_addr*)&remoteAddr.sin_addr.s_addr),ntohs(remoteAddr.sin_port));
    }
    // recvLen = recv(connectFd, buf, sizeof(buf), 0);
    // if (recvLen <= 0)
    // {
    //     printf("接收失败");
    // }
    // else
    // {
    //     printf("buf: %s\n", buf);
    // }
    
    close(connectFd);
    close(socketFd);

    return 0;
}