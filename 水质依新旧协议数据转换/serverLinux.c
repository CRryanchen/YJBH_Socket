
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>

#define PORT                2333     /**< �����˿� */
#define BACKLOG             5      /**< �������� */

int main(int argc, char * argv[])
{
    int socketFd = 0;               // socket�ļ�������
    int connectFd = 0;              // �������Ӻ���ļ�������
    int recvLen = 0;                // ������Ϣ�ķ���ֵ
    int ret = 0;

    char buf[4096];
    struct sockaddr_in localAddr = {0}; // ���ص�ַ��Ϣ
    struct sockaddr_in remoteAddr = {0};    // �Է���ַ��Ϣ
    socklen_t socklen = 0;

    socketFd = socket(AF_INET, SOCK_STREAM, 0); // ����socket
    if (socketFd < 0)
    {
        perror("socket");
        exit(0);
    }

    printf("�����׽��ֳɹ�\n");

    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(PORT);   // �˿ں�
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);   // ������ַ
    // localAddr.sin_addr.s_addr = inet_addr("192.168.0.108");

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
    connectFd = accept(socketFd, (struct sockaddr *)&remoteAddr, &sizeof(remoteAddr));
    if (connectFd < 0)
    {
        perror("accept");
        exit(0);
    }
    else
    {
        printf("���豸����");
        printf("Client from %s:%d \n",inet_ntoa(*(struct in_addr*)&remoteAddr.sin_addr.s_addr),ntohs(remoteAddr.sin_port));
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
    
    close(connectFd);
    close(socketFd);

    return 0;
}