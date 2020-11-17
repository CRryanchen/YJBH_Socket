#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <winsock2.h>
#include <unistd.h>
#include "deviceData.h"
#include "main.h"

#define PORT       23333	                  		/*!< �˿� */                 
#define IP_ADDRESS "118.24.246.188" 		    /*!< ������IP��ַ */            
// #define QZDL		                      		/*!< �������������ǿ�Ƶ������������������� */



void QzdlData(const char *imsi, float p34, float p36, float p37, float p38);
void XsyjData(char *imsi, float p33, float p34, float p35, float p36, float p37, float p38);
float RandomParam(float p);
float CurrentRandomParam(float p);
void myPrint(unsigned char *startAddr, unsigned char length);
void IMSItoCharBuf(const char *imsi, unsigned char *startAddr);
float EndianFloat(float value);
void SendDataToServer(SOCKET sock_fd);

unsigned char g_dataBuf[50];

int main(int argc, char * argv[])
{
	// ��ʼ��Winsocket����
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

	// ����ʱ��������
	srand((unsigned)time(NULL)); 
	
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
	ser_addr.sin_port = htons(PORT);
	//inet_pton(AF_INET, "118.24.246.188", &(ser_addr.sin_addr.s_addr));
	ser_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	
	                                         // ����
	int ret = connect(s_fd, (struct sockaddr *)&(ser_addr), sizeof(ser_addr));
	if (ret == SOCKET_ERROR)
	{
		perror("connect failed");
		return -1;
	}

	SendDataToServer(s_fd);
	
	closesocket(s_fd);
	WSACleanup();
	return 0;
}


void QzdlData(const char * imsi, float p34, float p36, float p37, float p38)
{
    struct NewProtocolQzdl QzdlDevice;

    // �ֽ�����
    QzdlDevice.m_totalBytes = 38;
    // �豸����
    QzdlDevice.m_deviceType = YJBH;
    // imsi��
    IMSItoCharBuf(imsi, QzdlDevice.m_deviceCardNum);
    // ϵͳ��λ��
    QzdlDevice.m_systemNum[0] = 0x00;
    QzdlDevice.m_systemNum[1] = 0x01;
    // ����
    p34 = RandomParam(p34);
	p36 = RandomParam(p36);
	p37 = RandomParam(p37);
	p38 = RandomParam(p38);
    QzdlDevice.m_params[0].m_paramID = 0x34;
    QzdlDevice.m_params[0].m_paramValue = EndianFloat(p34);
    QzdlDevice.m_params[0].m_paramState = 0;
    
    QzdlDevice.m_params[1].m_paramID = 0x36;
    QzdlDevice.m_params[1].m_paramValue = EndianFloat(p36);
    QzdlDevice.m_params[1].m_paramState = 0;

    QzdlDevice.m_params[2].m_paramID = 0x37;
    QzdlDevice.m_params[2].m_paramValue = EndianFloat(p37);
    QzdlDevice.m_params[2].m_paramState = 0;

    QzdlDevice.m_params[3].m_paramID = 0x38;
    QzdlDevice.m_params[3].m_paramValue = EndianFloat(p38);
    QzdlDevice.m_params[3].m_paramState = 0;

    QzdlDevice.m_checkNum.m_bytes[0] = 0xff;
    QzdlDevice.m_checkNum.m_bytes[1] = 0xff;

    printf("�ܹ���%d���ֽ�\n", sizeof(QzdlDevice));
    myPrint((unsigned char *)&QzdlDevice, sizeof(QzdlDevice));

    memset(g_dataBuf, 0, sizeof(g_dataBuf));
    memcpy(g_dataBuf, (void *)&QzdlDevice, sizeof(QzdlDevice));
}


void XsyjData(char * imsi, float p33, float p34, float p35, float p36, float p37, float p38)
{
    struct NewProtocolXsyj XsyjDevice;

    // �ֽ�����
    XsyjDevice.m_totalBytes = 50;
    // �豸����
    XsyjDevice.m_deviceType = YJBH;
    // imsi��
    IMSItoCharBuf(imsi, XsyjDevice.m_deviceCardNum);
    // ϵͳ��λ��
    XsyjDevice.m_systemNum[0] = 0x00;
    XsyjDevice.m_systemNum[1] = 0x01;
    // ����
    p33 = RandomParam(p33);
	p34 = RandomParam(p34);
	p35 = CurrentRandomParam(p35);
	p36 = RandomParam(p36);
	p37 = RandomParam(p37);
	p38 = RandomParam(p38);

    XsyjDevice.m_params[0].m_paramID = 0x33;
    XsyjDevice.m_params[0].m_paramValue = EndianFloat(p33);
    XsyjDevice.m_params[0].m_paramState = 0;

    XsyjDevice.m_params[1].m_paramID = 0x34;
    XsyjDevice.m_params[1].m_paramValue = EndianFloat(p34);
    XsyjDevice.m_params[1].m_paramState = 0;

    XsyjDevice.m_params[2].m_paramID = 0x35;
    XsyjDevice.m_params[2].m_paramValue = EndianFloat(p35);
    XsyjDevice.m_params[2].m_paramState = 0;

    XsyjDevice.m_params[3].m_paramID = 0x36;
    XsyjDevice.m_params[3].m_paramValue = EndianFloat(p36);
    XsyjDevice.m_params[3].m_paramState = 0;

    XsyjDevice.m_params[4].m_paramID = 0x37;
    XsyjDevice.m_params[4].m_paramValue = EndianFloat(p37);
    XsyjDevice.m_params[4].m_paramState = 0;

    XsyjDevice.m_params[5].m_paramID = 0x38;
    XsyjDevice.m_params[5].m_paramValue = EndianFloat(p38);
    XsyjDevice.m_params[5].m_paramState = 0;

    XsyjDevice.m_checkNum.m_bytes[0] = 0xff;
    XsyjDevice.m_checkNum.m_bytes[1] = 0xff;

    printf("�ܹ���%d���ֽ�\n", sizeof(XsyjDevice));
    myPrint((unsigned char *)&XsyjDevice, sizeof(XsyjDevice));
    memset(g_dataBuf, 0, sizeof(g_dataBuf));
    memcpy(g_dataBuf, (void *)&XsyjDevice, sizeof(XsyjDevice));
}



// ��������
float RandomParam(float p)
{
	return (rand() % 40 - 20) * 0.001 + p;
}


// ��������
float CurrentRandomParam(float p)
{
	float temp;
	do
	{
		temp = (rand() % 30000 -15000) * 0.001 + p;
	}while ((temp < 4.0) || (temp > 36.0));
	
	return temp;
}


/**
 * @brief  ��IMSI�ַ���ת��Ϊunsigned char����
 * @param  imsi             IMSI���ַ���
 * @param  startAddr        д�����ʼ��ַ
 */
void IMSItoCharBuf(const char * imsi, unsigned char * startAddr)
{
    unsigned char resultBuf[8];
    unsigned long long temp;

    unsigned short temp1;
    unsigned short temp2;
    unsigned short temp3;
    unsigned short temp4;

    // ��IMSI��ֳ�4���ֶ�ȡ
    temp1 = (*(imsi + 0) - 48) * 100 + (*(imsi + 1) - 48) * 10 + (*(imsi + 2) - 48);
    temp2 = (*(imsi + 3) - 48) * 1000 + (*(imsi + 4) - 48) * 100 + (*(imsi + 5) - 48) * 10 + (*(imsi + 6) - 48);
    temp3 = (*(imsi + 7) - 48) * 1000 + (*(imsi + 8) - 48) * 100 + (*(imsi + 9) - 48) * 10 + (*(imsi + 10) - 48);
    temp4 = (*(imsi + 11) - 48) * 1000 + (*(imsi + 12) - 48) * 100 + (*(imsi + 13) - 48) * 10 + (*(imsi + 14) - 48);

    resultBuf[0] = temp1 / 256;
    resultBuf[1] = temp1 % 256;
    resultBuf[2] = temp2 / 256;
    resultBuf[3] = temp2 % 256;
    resultBuf[4] = temp3 / 256;
    resultBuf[5] = temp3 % 256;
    resultBuf[6] = temp4 / 256;
    resultBuf[7] = temp4 % 256;

    memcpy(startAddr, resultBuf, 8);
}


/**
 * @brief  ��ӡͨ�ŵ��ֽ����ݣ����ڲ���
 * @param  startAddr        ��ʼ��ַ
 * @param  length           �ֽڳ���
 */
void myPrint(unsigned char * startAddr, unsigned char length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%02x  ", *(startAddr + i));
    }
    putchar('\n');
}

/**
 * @brief  float�������ݴ�С��
 * @param  value            ��Ҫת����ֵ
 * @return float            ת����ɵ�ֵ
 */
float EndianFloat(float value)
{
    union FloadAndFourBytes f1, f2;
    f1.m_floatValue = value;

    f2.m_bytes[0] = f1.m_bytes[3];
    f2.m_bytes[1] = f1.m_bytes[2];
    f2.m_bytes[2] = f1.m_bytes[1];
    f2.m_bytes[3] = f1.m_bytes[0];

    return f2.m_floatValue;
}

void SendDataToServer(SOCKET sock_fd)
{
#if defined QZDL
	printf("���ڷ��Ͱ����� ���� 3��׮��\n");
	QzdlData(BAIZI_3_IMSI, BAIZI_3_P34, BAIZI_3_P36, BAIZI_3_P37, BAIZI_3_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  3��׮���ͳɹ���\n");
	sleep(17);
	
	printf("���ڷ��Ͱ����� ���� 12��׮��\n");
	QzdlData(BAIZI_12_IMSI, BAIZI_12_P34, BAIZI_12_P36, BAIZI_12_P37, BAIZI_12_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  12��׮���ͳɹ���\n");
	sleep(56);
	
	printf("���ڷ��Ͱ����� ���� 4��׮��\n");
	QzdlData(ANLAN_4_IMSI, ANLAN_4_P34, ANLAN_4_P36, ANLAN_4_P37, ANLAN_4_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(18);
	
	printf("���ڷ��Ͱ����� ���� 1��׮��\n");
	QzdlData(BAIZI_1_IMSI, BAIZI_1_P34, BAIZI_1_P36, BAIZI_1_P37, BAIZI_1_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(31);
	
	
	printf("���ڷ��Ͱ����� ���� 3��׮��\n");
	QzdlData(ANLAN_3_IMSI, ANLAN_3_P34, ANLAN_3_P36, ANLAN_3_P37, ANLAN_3_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  3��׮���ͳɹ���\n");
	sleep(49);
	
	printf("���ڷ��Ͱ����� ���� 16��׮��\n");
	QzdlData(BAIZI_16_IMSI, BAIZI_16_P34, BAIZI_16_P36, BAIZI_16_P37, BAIZI_16_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  16��׮���ͳɹ���\n");
	sleep(17);
	
	printf("���ڷ��Ͱ����� ���� 1��׮��\n");
	QzdlData(ANLAN_1_IMSI, ANLAN_1_P34, ANLAN_1_P36, ANLAN_1_P37, ANLAN_1_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(22);
	
	printf("���ڷ��Ͱ����� ���� 14��׮��\n");
	QzdlData(BAIZI_14_IMSI, BAIZI_14_P34, BAIZI_14_P36, BAIZI_14_P37, BAIZI_14_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  14��׮���ͳɹ���\n");
	sleep(28);
	
	printf("���ڷ��Ͱ����� ���� 15��׮��\n");
	QzdlData(BAIZI_15_IMSI, BAIZI_15_P34, BAIZI_15_P36, BAIZI_15_P37, BAIZI_15_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  15��׮���ͳɹ���\n");
	sleep(32);

	printf("���ڷ��Ͱ����� ���� 10��׮��\n");
	QzdlData(BAIZI_10_IMSI, BAIZI_10_P34, BAIZI_10_P36, BAIZI_10_P37, BAIZI_10_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  10��׮���ͳɹ���\n");
	sleep(33);

	printf("���ڷ��Ͱ����� ���� 8��׮��\n");
	QzdlData(BAIZI_8_IMSI, BAIZI_8_P34, BAIZI_8_P36, BAIZI_8_P37, BAIZI_8_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  8��׮���ͳɹ���\n");
	sleep(66);
	
	printf("���ڷ��Ͱ����� ���� 7��׮��\n");
	QzdlData(BAIZI_7_IMSI, BAIZI_7_P34, BAIZI_7_P36, BAIZI_7_P37, BAIZI_7_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  7��׮���ͳɹ���\n");
	sleep(43);
	
	printf("���ڷ��Ͱ����� ���� 5��׮��\n");
	QzdlData(BAIZI_5_IMSI, BAIZI_5_P34, BAIZI_5_P36, BAIZI_5_P37, BAIZI_5_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  5��׮���ͳɹ���\n");
	sleep(21);
	
	printf("���ڷ��Ͱ����� ���� 17��׮��\n");
	QzdlData(BAIZI_17_IMSI, BAIZI_17_P34, BAIZI_17_P36, BAIZI_17_P37, BAIZI_17_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  17��׮���ͳɹ���\n");
	sleep(11);
	
	printf("���ڷ��Ͱ����� ���� 5��׮��\n");
	QzdlData(ANLAN_5_IMSI, ANLAN_5_P34, ANLAN_5_P36, ANLAN_5_P37, ANLAN_5_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  5��׮���ͳɹ���\n");
	sleep(28);
	
	printf("���ڷ��Ͱ����� ���� 4��׮��\n");
	QzdlData(BAIZI_4_IMSI, BAIZI_4_P34, BAIZI_4_P36, BAIZI_4_P37, BAIZI_4_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(61);

	printf("���ڷ��Ͱ����� ���� 9��׮��\n");
	QzdlData(BAIZI_9_IMSI, BAIZI_9_P34, BAIZI_9_P36, BAIZI_9_P37, BAIZI_9_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("������ ����  9��׮���ͳɹ���\n");
	sleep(12);

#else
	printf("���ڷ����⻷���϶� ���� 15��׮��\n");
	XsyjDate(BANAN_15_IMSI, BANAN_15_P33, BANAN_15_P34, BANAN_15_P35, BANAN_15_P36, BANAN_15_P37, BANAN_15_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  15��׮���ͳɹ���\n");
	sleep(13);
	
	printf("���ڷ����⻷���϶� ���� 16��׮��\n");
	XsyjDate(BANAN_16_IMSI, BANAN_16_P33, BANAN_16_P34, BANAN_16_P35, BANAN_16_P36, BANAN_16_P37, BANAN_16_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  16��׮���ͳɹ���\n");
	sleep(25);
	
	
	
	printf("���ڷ�����ͷ�� ���� 7��׮��\n");
	XsyjDate(RENTOU_7_IMSI, RENTOU_7_P33, RENTOU_7_P34, RENTOU_7_P35, RENTOU_7_P36, RENTOU_7_P37, RENTOU_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ͷ�� ����  7��׮���ͳɹ���\n");
	sleep(38);
	
	
	
	printf("���ڷ��ͺ����� ���� 17��׮��\n");
	XsyjDate(HANWANG_17_IMSI, HANWANG_17_P33, HANWANG_17_P34, HANWANG_17_P35, HANWANG_17_P36, HANWANG_17_P37, HANWANG_17_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  17��׮���ͳɹ���\n");
	sleep(4);
	
	printf("���ڷ����⻷���϶� ���� 14��׮��\n");
	XsyjDate(BANAN_14_IMSI, BANAN_14_P33, BANAN_14_P34, BANAN_14_P35, BANAN_14_P36, BANAN_14_P37, BANAN_14_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  14��׮���ͳɹ���\n");
	sleep(35);
	
	printf("���ڷ����⻷���϶� ���� 11��׮��\n");
	XsyjDate(BANAN_11_IMSI, BANAN_11_P33, BANAN_11_P34, BANAN_11_P35, BANAN_11_P36, BANAN_11_P37, BANAN_11_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  11��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 17��׮��\n");
	XsyjDate(BANAN_17_IMSI, BANAN_17_P33, BANAN_17_P34, BANAN_17_P35, BANAN_17_P36, BANAN_17_P37, BANAN_17_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  17��׮���ͳɹ���\n");
	sleep(54);
	
	printf("���ڷ����ϳ��� ���� 5��׮��\n");
	XsyjDate(SHANGCHANG_5_IMSI, SHANGCHANG_5_P33, SHANGCHANG_5_P34, SHANGCHANG_5_P35, SHANGCHANG_5_P36, SHANGCHANG_5_P37, SHANGCHANG_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�ϳ��� ����  5��׮���ͳɹ���\n");
	sleep(32);
	
	printf("���ڷ��ͳ����� ���� 1��׮��\n");
	XsyjDate(CHANGAN_1_IMSI, CHANGAN_1_P33, CHANGAN_1_P34, CHANGAN_1_P35, CHANGAN_1_P36, CHANGAN_1_P37, CHANGAN_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(12);
	
	printf("���ڷ�����ֽ�� ���� 3��׮��\n");
	XsyjDate(ZAOZHI_3_IMSI, ZAOZHI_3_P33, ZAOZHI_3_P34, ZAOZHI_3_P35, ZAOZHI_3_P36, ZAOZHI_3_P37, ZAOZHI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ֽ�� ����  3��׮���ͳɹ���\n");
	sleep(43);
	
	printf("���ڷ��������� ���� 2��׮��\n");
	XsyjDate(SIQI_2_IMSI, SIQI_2_P33, SIQI_2_P34, SIQI_2_P35, SIQI_2_P36, SIQI_2_P37, SIQI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  2��׮���ͳɹ���\n");
	sleep(25);
	
	printf("���ڷ����⻷���϶� ���� 4��׮��\n");
	XsyjDate(BANAN_4_IMSI, BANAN_4_P33, BANAN_4_P34, BANAN_4_P35, BANAN_4_P36, BANAN_4_P37, BANAN_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  4��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ�������� ���� �Ƽ����ɳ�����\n");
	XsyjDate(WUGUI_TJT_IMSI, WUGUI_TJT_P33, WUGUI_TJT_P34, WUGUI_TJT_P35, WUGUI_TJT_P36, WUGUI_TJT_P37, WUGUI_TJT_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("����� ����  �Ƽ����ɳ������ͳɹ���\n");
	sleep(1);
	
	
	
	
	printf("���ڷ��ͺ����� ���� 16��׮��\n");
	XsyjDate(HANWANG_16_IMSI, HANWANG_16_P33, HANWANG_16_P34, HANWANG_16_P35, HANWANG_16_P36, HANWANG_16_P37, HANWANG_16_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  16��׮���ͳɹ���\n");
	sleep(43);
	
	
	printf("���ڷ����⻷���϶� ���� 3��׮��\n");
	XsyjDate(BANAN_3_IMSI, BANAN_3_P33, BANAN_3_P34, BANAN_3_P35, BANAN_3_P36, BANAN_3_P37, BANAN_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  3��׮���ͳɹ���\n");
	sleep(44);
	
	
	
	printf("���ڷ�����ֽ�� ���� 1��׮��\n");
	XsyjDate(ZAOZHI_1_IMSI, ZAOZHI_1_P33, ZAOZHI_1_P34, ZAOZHI_1_P35, ZAOZHI_1_P36, ZAOZHI_1_P37, ZAOZHI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ֽ�� ����  1��׮���ͳɹ���\n");
	sleep(17);
	
	
	
	printf("���ڷ����⻷���϶� ���� 7��׮��\n");
	XsyjDate(BANAN_7_IMSI, BANAN_7_P33, BANAN_7_P34, BANAN_7_P35, BANAN_7_P36, BANAN_7_P37, BANAN_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  7��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 9��׮��\n");
	XsyjDate(BANAN_9_IMSI, BANAN_9_P33, BANAN_9_P34, BANAN_9_P35, BANAN_9_P36, BANAN_9_P37, BANAN_9_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  9��׮���ͳɹ���\n");
	sleep(41);
	
	printf("���ڷ����ĺ��� ���� 1��׮��\n");
	XsyjDate(SIHAI_1_IMSI, SIHAI_1_P33, SIHAI_1_P34, SIHAI_1_P35, SIHAI_1_P36, SIHAI_1_P37, SIHAI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�ĺ��� ����  1��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 12��׮��\n");
	XsyjDate(BANAN_12_IMSI, BANAN_12_P33, BANAN_12_P34, BANAN_12_P35, BANAN_12_P36, BANAN_12_P37, BANAN_12_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  12��׮���ͳɹ���\n");
	sleep(54);
	
	printf("���ڷ����ϳ��� ���� 4��׮��\n");
	XsyjDate(SHANGCHANG_4_IMSI, SHANGCHANG_4_P33, SHANGCHANG_4_P34, SHANGCHANG_4_P35, SHANGCHANG_4_P36, SHANGCHANG_4_P37, SHANGCHANG_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�ϳ��� ����  4��׮���ͳɹ���\n");
	sleep(2);
	
	printf("���ڷ��ͳ����� ���� 2��׮��\n");
	XsyjDate(CHANGAN_2_IMSI, CHANGAN_2_P33, CHANGAN_2_P34, CHANGAN_2_P35, CHANGAN_2_P36, CHANGAN_2_P37, CHANGAN_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  2��׮���ͳɹ���\n");
	sleep(21);
	
	printf("���ڷ�������� ���� ����԰��\n");
	XsyjDate(WUGUI_GSY_IMSI, WUGUI_GSY_P33, WUGUI_GSY_P34, WUGUI_GSY_P35, WUGUI_GSY_P36, WUGUI_GSY_P37, WUGUI_GSY_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("����� ����  ����԰���ͳɹ���\n");
	sleep(26);
	
	printf("���ڷ�����ͷ�� ���� 2��׮��\n");
	XsyjDate(RENTOU_2_IMSI, RENTOU_2_P33, RENTOU_2_P34, RENTOU_2_P35, RENTOU_2_P36, RENTOU_2_P37, RENTOU_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ͷ�� ����  2��׮���ͳɹ���\n");
	sleep(12);
	
	printf("���ڷ����Ĳ��� ���� 7��׮��\n");
	XsyjDate(SICAI_7_IMSI, SICAI_7_P33, SICAI_7_P34, SICAI_7_P35, SICAI_7_P36, SICAI_7_P37, SICAI_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�Ĳ��� ����  7��׮���ͳɹ���\n");
	sleep(19);
	
	
	
	
	
	printf("���ڷ����⻷���϶� ���� 13��׮��\n");
	XsyjDate(BANAN_13_IMSI, BANAN_13_P33, BANAN_13_P34, BANAN_13_P35, BANAN_13_P36, BANAN_13_P37, BANAN_13_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  13��׮���ͳɹ���\n");
	sleep(14);
	
	printf("���ڷ����⻷���϶� ���� 1��׮��\n");
	XsyjDate(BANAN_1_IMSI, BANAN_1_P33, BANAN_1_P34, BANAN_1_P35, BANAN_1_P36, BANAN_1_P37, BANAN_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  1��׮���ͳɹ���\n");
	sleep(42);
	
	printf("���ڷ����⻷���϶� ���� 5��׮��\n");
	XsyjDate(BANAN_5_IMSI, BANAN_5_P33, BANAN_5_P34, BANAN_5_P35, BANAN_5_P36, BANAN_5_P37, BANAN_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  5��׮���ͳɹ���\n");
	sleep(11);
	
	printf("���ڷ��������� ���� 7��׮��\n");
	XsyjDate(SIQI_7_IMSI, SIQI_7_P33, SIQI_7_P34, SIQI_7_P35, SIQI_7_P36, SIQI_7_P37, SIQI_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  7��׮���ͳɹ���\n");
	sleep(26);
	
	printf("���ڷ����⻷���϶� ���� 8��׮��\n");
	XsyjDate(BANAN_8_IMSI, BANAN_8_P33, BANAN_8_P34, BANAN_8_P35, BANAN_8_P36, BANAN_8_P37, BANAN_8_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  8��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ��ͳ����� ���� 4��׮��\n");
	XsyjDate(CHANGAN_4_IMSI, CHANGAN_4_P33, CHANGAN_4_P34, CHANGAN_4_P35, CHANGAN_4_P36, CHANGAN_4_P37, CHANGAN_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(41);
	
	printf("���ڷ�����ֽ�� ���� 2��׮��\n");
	XsyjDate(ZAOZHI_2_IMSI, ZAOZHI_2_P33, ZAOZHI_2_P34, ZAOZHI_2_P35, ZAOZHI_2_P36, ZAOZHI_2_P37, ZAOZHI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ֽ�� ����  2��׮���ͳɹ���\n");
	sleep(8);
	
	printf("���ڷ�������� ���� �ֲ��г��ԣ�\n");
	XsyjDate(WUGUI_GCS_IMSI, WUGUI_GCS_P33, WUGUI_GCS_P34, WUGUI_GCS_P35, WUGUI_GCS_P36, WUGUI_GCS_P37, WUGUI_GCS_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("����� ����  �ֲ��г��Է��ͳɹ���\n");
	sleep(16);
	
	printf("���ڷ�����ͷ�� ���� 5��׮��\n");
	XsyjDate(RENTOU_5_IMSI, RENTOU_5_P33, RENTOU_5_P34, RENTOU_5_P35, RENTOU_5_P36, RENTOU_5_P37, RENTOU_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("��ͷ�� ����  5��׮���ͳɹ���\n");
	sleep(24);
	
	printf("���ڷ����⻷���϶� ���� 6��׮��\n");
	XsyjDate(BANAN_6_IMSI, BANAN_6_P33, BANAN_6_P34, BANAN_6_P35, BANAN_6_P36, BANAN_6_P37, BANAN_6_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  6��׮���ͳɹ���\n");
	sleep(42);
	
	printf("���ڷ����⻷���϶� ���� 18��׮��\n");
	XsyjDate(BANAN_18_IMSI, BANAN_18_P33, BANAN_18_P34, BANAN_18_P35, BANAN_18_P36, BANAN_18_P37, BANAN_18_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  18��׮���ͳɹ���\n");
	sleep(30);
	
	printf("���ڷ�������� ���� ������������վ�ԣ�\n");
	XsyjDate(WUGUI_BFQ_IMSI, WUGUI_BFQ_P33, WUGUI_BFQ_P34, WUGUI_BFQ_P35, WUGUI_BFQ_P36, WUGUI_BFQ_P37, WUGUI_BFQ_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("����� ����  ������������վ�Է��ͳɹ���\n");
	sleep(20);

	printf("���ڷ����⻷���϶� ���� 2��׮��\n");
	XsyjDate(BANAN_2_IMSI, BANAN_2_P33, BANAN_2_P34, BANAN_2_P35, BANAN_2_P36, BANAN_2_P37, BANAN_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  2��׮���ͳɹ���\n");
	sleep(15);
	
	
	printf("���ڷ����ĺ��� ���� 3��׮��\n");
	XsyjDate(SIHAI_3_IMSI, SIHAI_3_P33, SIHAI_3_P34, SIHAI_3_P35, SIHAI_3_P36, SIHAI_3_P37, SIHAI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�ĺ��� ����  3��׮���ͳɹ���\n");
	sleep(45);
	
	printf("���ڷ����⻷���϶� ���� 10��׮��\n");
	XsyjDate(BANAN_10_IMSI, BANAN_10_P33, BANAN_10_P34, BANAN_10_P35, BANAN_10_P36, BANAN_10_P37, BANAN_10_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("�⻷���϶� ����  10��׮���ͳɹ���\n");
	sleep(1);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 5��׮��\n");
	XsyjDate(CAIYUAN_5_IMSI, CAIYUAN_5_P33, CAIYUAN_5_P34, CAIYUAN_5_P35, CAIYUAN_5_P36, CAIYUAN_5_P37, CAIYUAN_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 5��׮���ͳɹ���\n");
	sleep(21);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 8��׮��\n");
	XsyjDate(CAIYUAN_8_IMSI, CAIYUAN_8_P33, CAIYUAN_8_P34, CAIYUAN_8_P35, CAIYUAN_8_P36, CAIYUAN_8_P37, CAIYUAN_8_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 8��׮���ͳɹ���\n");
	sleep(11);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 10��׮��\n");
	XsyjDate(CAIYUAN_10_IMSI, CAIYUAN_10_P33, CAIYUAN_10_P34, CAIYUAN_10_P35, CAIYUAN_10_P36, CAIYUAN_10_P37, CAIYUAN_10_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 10��׮���ͳɹ���\n");
	sleep(15);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 426��׮��\n");
	XsyjDate(CAIYUAN_426_IMSI, CAIYUAN_426_P33, CAIYUAN_426_P34, CAIYUAN_426_P35, CAIYUAN_426_P36, CAIYUAN_426_P37, CAIYUAN_426_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 426��׮���ͳɹ���\n");
	sleep(15);

	printf("���ڷ���ʵ���� ���� 1��׮��\n");
	XsyjDate(YANSHI_1_IMSI, YANSHI_1_P33, YANSHI_1_P34, YANSHI_1_P35, YANSHI_1_P36, YANSHI_1_P37, YANSHI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("ʵ���� ���� 1��׮���ͳɹ���\n");
	sleep(13);

	printf("���ڷ���ʵ���� ���� 2��׮��\n");
	XsyjDate(YANSHI_2_IMSI, YANSHI_2_P33, YANSHI_2_P34, YANSHI_2_P35, YANSHI_2_P36, YANSHI_2_P37, YANSHI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("ʵ���� ���� 2��׮���ͳɹ���\n");
	sleep(33);

	printf("���ڷ���ʵ���� ���� 3��׮��\n");
	XsyjDate(YANSHI_3_IMSI, YANSHI_3_P33, YANSHI_3_P34, YANSHI_3_P35, YANSHI_3_P36, YANSHI_3_P37, YANSHI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("ʵ���� ���� 3��׮���ͳɹ���\n");
	sleep(20);
#endif                                    /* QZDL */
}