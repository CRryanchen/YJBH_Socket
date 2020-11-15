
#include <stdio.h>
#include <winsock2.h>
#include "oldTonewProtocol.h"

#define PORT                2333     /**< �����˿� */
#define BACKLOG             5      /**< �������� */

int repost(unsigned char * addr, int length);

int main(int argc, char * argv[])
{
    SOCKET socketFd = 0;               // socket�ļ�������
    SOCKET connectFd = 0;              // �������Ӻ���ļ�������
    int ret = 0;

    struct sockaddr_in localAddr = {0}; // ���ص�ַ��Ϣ
    SOCKADDR  remoteAddr = {0};    // �Է���ַ��Ϣ

    // ��ʼ��Winsocket����
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

    socketFd = socket(AF_INET, SOCK_STREAM, 0); // ����socket
    if (socketFd == INVALID_SOCKET)
    {
        perror("socket");
        exit(0);
    }

    printf("�����׽��ֳɹ�\n");

    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(PORT);   // �˿ں�
    localAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // �󶨵�ַ�ṹ���socket
    ret = bind(socketFd, (const struct sockaddr *)&localAddr, sizeof(localAddr));
    if (ret < 0)
    {
        perror("bind");
        exit(0);
    }

    printf("�󶨵�ַ�ɹ�\n");
    
    // �����������ڶ�����������������
    ret = 0;
    ret = listen(socketFd, BACKLOG);
    if (ret < 0)
    {
        perror("listen");
        exit(0);
    }

    printf("�����ɹ�\n");
    
    // ����ֱ��������
    int size = sizeof(remoteAddr);
    connectFd = accept(socketFd, (struct sockaddr *)&remoteAddr, &size);
    if (connectFd < 0)
    {
        perror("accept");
        exit(0);
    }
    else
    {
        printf("���豸����");
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
    //     printf("����ʧ��");
    // }
    // else
    // {
    //     printf("buf: %s\n", buf);
    // }
    
    closesocket(connectFd);
    closesocket(socketFd);

    WSACleanup();            //ж��

    return 0;
}


int repost(unsigned char * addr, int length)
{
	// ��ʼ��Winsocket����
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

	// �����׽���
	SOCKET s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd == INVALID_SOCKET)
	{
		perror("creact stream socket failed");
		return -1;
	}
	
    // IPV4��ַ�ṹ�帳ֵ
	struct sockaddr_in ser_addr;
	ser_addr.sin_family = AF_INET;
	// ser_addr.sin_port = htons(PORT); 
    ser_addr.sin_port = htons(2334);                                        //inet_pton(AF_INET, "118.24.246.188", &(ser_addr.sin_addr.s_addr));
	// ser_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	                                         // ����
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