
#include <stdio.h>
#include <winsock2.h>
#include "oldTonewProtocol.h"

#define PORT                2333     /**< 监听端口 */
#define BACKLOG             5      /**< 最大监听数 */

int repost(unsigned char * addr, int length);

int main(int argc, char * argv[])
{
    SOCKET socketFd = 0;               // socket文件描述符
    SOCKET connectFd = 0;              // 建立连接后的文件描述符
    int ret = 0;

    struct sockaddr_in localAddr = {0}; // 本地地址信息
    SOCKADDR  remoteAddr = {0};    // 对方地址信息

    // 初始化Winsocket服务
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

    socketFd = socket(AF_INET, SOCK_STREAM, 0); // 建立socket
    if (socketFd == INVALID_SOCKET)
    {
        perror("socket");
        exit(0);
    }

    printf("创建套接字成功\n");

    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(PORT);   // 端口号
    localAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

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
    int size = sizeof(remoteAddr);
    connectFd = accept(socketFd, (struct sockaddr *)&remoteAddr, &size);
    if (connectFd < 0)
    {
        perror("accept");
        exit(0);
    }
    else
    {
        printf("有设备接入");
        // printf("Client from %s:%d \n",inet_ntoa(*(struct in_addr*)&remoteAddr.sin_addr.s_addr),ntohs(remoteAddr.sin_port));
    }

    char * msg = "Hello, my Client.\n";
    send(connectFd, msg, strlen(msg) + sizeof(char), 0);

    unsigned char buf[4096] = {0};
    int recvlen = 0;
    while (1)
    {
        recvlen = recv(connectFd, buf, 4096, 0);
        if (recvlen <= 0)
        {
            break;
        }
        
        for (int i = 0; i < recvlen; i++)
        {
            printf("%02x ", buf[i]);
        }
        
        printf("recvlen = %d\n", recvlen);


        /*------------------------------*/
        struct NewProtocol szyNewProtocol;
        struct OldProtocol szyOldProtocol;

        szyOldProtocol = *(struct OldProtocol *)buf;
        oldCopyToNewProtocol(&szyNewProtocol, &szyOldProtocol);

        myPrint((unsigned char *)&szyNewProtocol, sizeof(szyNewProtocol));

        repost((unsigned char *)&szyNewProtocol, recvlen);
        /*------------------------------*/
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
    
    closesocket(connectFd);
    closesocket(socketFd);

    WSACleanup();            //卸载

    return 0;
}


int repost(unsigned char * addr, int length)
{
	// 初始化Winsocket服务
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

	// 创建套接字
	SOCKET s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd == INVALID_SOCKET)
	{
		perror("creact stream socket failed");
		return -1;
	}
	
    // IPV4地址结构体赋值
	struct sockaddr_in ser_addr;
	ser_addr.sin_family = AF_INET;
	// ser_addr.sin_port = htons(PORT); 
    ser_addr.sin_port = htons(2334);                                        //inet_pton(AF_INET, "118.24.246.188", &(ser_addr.sin_addr.s_addr));
	// ser_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	                                         // 连接
	int ret = connect(s_fd, (struct sockaddr *)&(ser_addr), sizeof(ser_addr));
	if (ret == SOCKET_ERROR)
	{
		perror("connect failed");
		return -1;
	}

    send(s_fd, addr, length, 0);
	
	closesocket(s_fd);
	WSACleanup();
}