#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <winsock2.h>
#include <unistd.h>
#include "deviceData.h"
#include "main.h"

#define PORT       23333	                  		/*!< 端口 */                 
#define IP_ADDRESS "118.24.246.188" 		    /*!< 服务器IP地址 */            
// #define QZDL		                      		/*!< 这个宏用于区分强制电流还是牺牲阳极类型 */



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
	// 初始化Winsocket服务
	WSADATA Ws;
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		perror("Init Windows Socket Failed");
		return -1;
	}

	// 重置时间数种子
	srand((unsigned)time(NULL)); 
	
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
	ser_addr.sin_port = htons(PORT);
	//inet_pton(AF_INET, "118.24.246.188", &(ser_addr.sin_addr.s_addr));
	ser_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	
	                                         // 连接
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

    // 字节总数
    QzdlDevice.m_totalBytes = 38;
    // 设备类型
    QzdlDevice.m_deviceType = YJBH;
    // imsi码
    IMSItoCharBuf(imsi, QzdlDevice.m_deviceCardNum);
    // 系统工位号
    QzdlDevice.m_systemNum[0] = 0x00;
    QzdlDevice.m_systemNum[1] = 0x01;
    // 参数
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

    printf("总共有%d个字节\n", sizeof(QzdlDevice));
    myPrint((unsigned char *)&QzdlDevice, sizeof(QzdlDevice));

    memset(g_dataBuf, 0, sizeof(g_dataBuf));
    memcpy(g_dataBuf, (void *)&QzdlDevice, sizeof(QzdlDevice));
}


void XsyjData(char * imsi, float p33, float p34, float p35, float p36, float p37, float p38)
{
    struct NewProtocolXsyj XsyjDevice;

    // 字节总数
    XsyjDevice.m_totalBytes = 50;
    // 设备类型
    XsyjDevice.m_deviceType = YJBH;
    // imsi码
    IMSItoCharBuf(imsi, XsyjDevice.m_deviceCardNum);
    // 系统工位号
    XsyjDevice.m_systemNum[0] = 0x00;
    XsyjDevice.m_systemNum[1] = 0x01;
    // 参数
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

    printf("总共有%d个字节\n", sizeof(XsyjDevice));
    myPrint((unsigned char *)&XsyjDevice, sizeof(XsyjDevice));
    memset(g_dataBuf, 0, sizeof(g_dataBuf));
    memcpy(g_dataBuf, (void *)&XsyjDevice, sizeof(XsyjDevice));
}



// 参数波动
float RandomParam(float p)
{
	return (rand() % 40 - 20) * 0.001 + p;
}


// 电流波动
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
 * @brief  将IMSI字符串转换为unsigned char数组
 * @param  imsi             IMSI码字符串
 * @param  startAddr        写入的起始地址
 */
void IMSItoCharBuf(const char * imsi, unsigned char * startAddr)
{
    unsigned char resultBuf[8];
    unsigned long long temp;

    unsigned short temp1;
    unsigned short temp2;
    unsigned short temp3;
    unsigned short temp4;

    // 将IMSI码分成4部分读取
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
 * @brief  打印通信的字节数据，用于测试
 * @param  startAddr        起始地址
 * @param  length           字节长度
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
 * @brief  float类型数据大小端
 * @param  value            需要转换的值
 * @return float            转换完成的值
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
	printf("正在发送白梓线 —— 3号桩：\n");
	QzdlData(BAIZI_3_IMSI, BAIZI_3_P34, BAIZI_3_P36, BAIZI_3_P37, BAIZI_3_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  3号桩发送成功。\n");
	sleep(17);
	
	printf("正在发送白梓线 —— 12号桩：\n");
	QzdlData(BAIZI_12_IMSI, BAIZI_12_P34, BAIZI_12_P36, BAIZI_12_P37, BAIZI_12_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  12号桩发送成功。\n");
	sleep(56);
	
	printf("正在发送安澜线 —— 4号桩：\n");
	QzdlData(ANLAN_4_IMSI, ANLAN_4_P34, ANLAN_4_P36, ANLAN_4_P37, ANLAN_4_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("安澜线 ——  4号桩发送成功。\n");
	sleep(18);
	
	printf("正在发送白梓线 —— 1号桩：\n");
	QzdlData(BAIZI_1_IMSI, BAIZI_1_P34, BAIZI_1_P36, BAIZI_1_P37, BAIZI_1_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  1号桩发送成功。\n");
	sleep(31);
	
	
	printf("正在发送安澜线 —— 3号桩：\n");
	QzdlData(ANLAN_3_IMSI, ANLAN_3_P34, ANLAN_3_P36, ANLAN_3_P37, ANLAN_3_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("安澜线 ——  3号桩发送成功。\n");
	sleep(49);
	
	printf("正在发送白梓线 —— 16号桩：\n");
	QzdlData(BAIZI_16_IMSI, BAIZI_16_P34, BAIZI_16_P36, BAIZI_16_P37, BAIZI_16_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  16号桩发送成功。\n");
	sleep(17);
	
	printf("正在发送安澜线 —— 1号桩：\n");
	QzdlData(ANLAN_1_IMSI, ANLAN_1_P34, ANLAN_1_P36, ANLAN_1_P37, ANLAN_1_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("安澜线 ——  1号桩发送成功。\n");
	sleep(22);
	
	printf("正在发送白梓线 —— 14号桩：\n");
	QzdlData(BAIZI_14_IMSI, BAIZI_14_P34, BAIZI_14_P36, BAIZI_14_P37, BAIZI_14_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  14号桩发送成功。\n");
	sleep(28);
	
	printf("正在发送白梓线 —— 15号桩：\n");
	QzdlData(BAIZI_15_IMSI, BAIZI_15_P34, BAIZI_15_P36, BAIZI_15_P37, BAIZI_15_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  15号桩发送成功。\n");
	sleep(32);

	printf("正在发送白梓线 —— 10号桩：\n");
	QzdlData(BAIZI_10_IMSI, BAIZI_10_P34, BAIZI_10_P36, BAIZI_10_P37, BAIZI_10_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  10号桩发送成功。\n");
	sleep(33);

	printf("正在发送白梓线 —— 8号桩：\n");
	QzdlData(BAIZI_8_IMSI, BAIZI_8_P34, BAIZI_8_P36, BAIZI_8_P37, BAIZI_8_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  8号桩发送成功。\n");
	sleep(66);
	
	printf("正在发送白梓线 —— 7号桩：\n");
	QzdlData(BAIZI_7_IMSI, BAIZI_7_P34, BAIZI_7_P36, BAIZI_7_P37, BAIZI_7_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  7号桩发送成功。\n");
	sleep(43);
	
	printf("正在发送白梓线 —— 5号桩：\n");
	QzdlData(BAIZI_5_IMSI, BAIZI_5_P34, BAIZI_5_P36, BAIZI_5_P37, BAIZI_5_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  5号桩发送成功。\n");
	sleep(21);
	
	printf("正在发送白梓线 —— 17号桩：\n");
	QzdlData(BAIZI_17_IMSI, BAIZI_17_P34, BAIZI_17_P36, BAIZI_17_P37, BAIZI_17_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  17号桩发送成功。\n");
	sleep(11);
	
	printf("正在发送安澜线 —— 5号桩：\n");
	QzdlData(ANLAN_5_IMSI, ANLAN_5_P34, ANLAN_5_P36, ANLAN_5_P37, ANLAN_5_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("安澜线 ——  5号桩发送成功。\n");
	sleep(28);
	
	printf("正在发送白梓线 —— 4号桩：\n");
	QzdlData(BAIZI_4_IMSI, BAIZI_4_P34, BAIZI_4_P36, BAIZI_4_P37, BAIZI_4_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  4号桩发送成功。\n");
	sleep(61);

	printf("正在发送白梓线 —— 9号桩：\n");
	QzdlData(BAIZI_9_IMSI, BAIZI_9_P34, BAIZI_9_P36, BAIZI_9_P37, BAIZI_9_P38);
	send(sock_fd, g_dataBuf, 38, 0);
	printf("白梓线 ——  9号桩发送成功。\n");
	sleep(12);

#else
	printf("正在发送外环巴南段 —— 15号桩：\n");
	XsyjDate(BANAN_15_IMSI, BANAN_15_P33, BANAN_15_P34, BANAN_15_P35, BANAN_15_P36, BANAN_15_P37, BANAN_15_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  15号桩发送成功。\n");
	sleep(13);
	
	printf("正在发送外环巴南段 —— 16号桩：\n");
	XsyjDate(BANAN_16_IMSI, BANAN_16_P33, BANAN_16_P34, BANAN_16_P35, BANAN_16_P36, BANAN_16_P37, BANAN_16_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  16号桩发送成功。\n");
	sleep(25);
	
	
	
	printf("正在发送人头线 —— 7号桩：\n");
	XsyjDate(RENTOU_7_IMSI, RENTOU_7_P33, RENTOU_7_P34, RENTOU_7_P35, RENTOU_7_P36, RENTOU_7_P37, RENTOU_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("人头线 ——  7号桩发送成功。\n");
	sleep(38);
	
	
	
	printf("正在发送旱望线 —— 17号桩：\n");
	XsyjDate(HANWANG_17_IMSI, HANWANG_17_P33, HANWANG_17_P34, HANWANG_17_P35, HANWANG_17_P36, HANWANG_17_P37, HANWANG_17_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("旱望线 ——  17号桩发送成功。\n");
	sleep(4);
	
	printf("正在发送外环巴南段 —— 14号桩：\n");
	XsyjDate(BANAN_14_IMSI, BANAN_14_P33, BANAN_14_P34, BANAN_14_P35, BANAN_14_P36, BANAN_14_P37, BANAN_14_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  14号桩发送成功。\n");
	sleep(35);
	
	printf("正在发送外环巴南段 —— 11号桩：\n");
	XsyjDate(BANAN_11_IMSI, BANAN_11_P33, BANAN_11_P34, BANAN_11_P35, BANAN_11_P36, BANAN_11_P37, BANAN_11_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  11号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 17号桩：\n");
	XsyjDate(BANAN_17_IMSI, BANAN_17_P33, BANAN_17_P34, BANAN_17_P35, BANAN_17_P36, BANAN_17_P37, BANAN_17_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  17号桩发送成功。\n");
	sleep(54);
	
	printf("正在发送上长线 —— 5号桩：\n");
	XsyjDate(SHANGCHANG_5_IMSI, SHANGCHANG_5_P33, SHANGCHANG_5_P34, SHANGCHANG_5_P35, SHANGCHANG_5_P36, SHANGCHANG_5_P37, SHANGCHANG_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("上长线 ——  5号桩发送成功。\n");
	sleep(32);
	
	printf("正在发送长安线 —— 1号桩：\n");
	XsyjDate(CHANGAN_1_IMSI, CHANGAN_1_P33, CHANGAN_1_P34, CHANGAN_1_P35, CHANGAN_1_P36, CHANGAN_1_P37, CHANGAN_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("长安线 ——  1号桩发送成功。\n");
	sleep(12);
	
	printf("正在发送造纸线 —— 3号桩：\n");
	XsyjDate(ZAOZHI_3_IMSI, ZAOZHI_3_P33, ZAOZHI_3_P34, ZAOZHI_3_P35, ZAOZHI_3_P36, ZAOZHI_3_P37, ZAOZHI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("造纸线 ——  3号桩发送成功。\n");
	sleep(43);
	
	printf("正在发送四七线 —— 2号桩：\n");
	XsyjDate(SIQI_2_IMSI, SIQI_2_P33, SIQI_2_P34, SIQI_2_P35, SIQI_2_P36, SIQI_2_P37, SIQI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("四七线 ——  2号桩发送成功。\n");
	sleep(25);
	
	printf("正在发送外环巴南段 —— 4号桩：\n");
	XsyjDate(BANAN_4_IMSI, BANAN_4_P33, BANAN_4_P34, BANAN_4_P35, BANAN_4_P36, BANAN_4_P37, BANAN_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  4号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送伍桂线 —— 唐家沱派出所：\n");
	XsyjDate(WUGUI_TJT_IMSI, WUGUI_TJT_P33, WUGUI_TJT_P34, WUGUI_TJT_P35, WUGUI_TJT_P36, WUGUI_TJT_P37, WUGUI_TJT_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("伍桂线 ——  唐家沱派出所发送成功。\n");
	sleep(1);
	
	
	
	
	printf("正在发送旱望线 —— 16号桩：\n");
	XsyjDate(HANWANG_16_IMSI, HANWANG_16_P33, HANWANG_16_P34, HANWANG_16_P35, HANWANG_16_P36, HANWANG_16_P37, HANWANG_16_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("旱望线 ——  16号桩发送成功。\n");
	sleep(43);
	
	
	printf("正在发送外环巴南段 —— 3号桩：\n");
	XsyjDate(BANAN_3_IMSI, BANAN_3_P33, BANAN_3_P34, BANAN_3_P35, BANAN_3_P36, BANAN_3_P37, BANAN_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  3号桩发送成功。\n");
	sleep(44);
	
	
	
	printf("正在发送造纸线 —— 1号桩：\n");
	XsyjDate(ZAOZHI_1_IMSI, ZAOZHI_1_P33, ZAOZHI_1_P34, ZAOZHI_1_P35, ZAOZHI_1_P36, ZAOZHI_1_P37, ZAOZHI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("造纸线 ——  1号桩发送成功。\n");
	sleep(17);
	
	
	
	printf("正在发送外环巴南段 —— 7号桩：\n");
	XsyjDate(BANAN_7_IMSI, BANAN_7_P33, BANAN_7_P34, BANAN_7_P35, BANAN_7_P36, BANAN_7_P37, BANAN_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  7号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 9号桩：\n");
	XsyjDate(BANAN_9_IMSI, BANAN_9_P33, BANAN_9_P34, BANAN_9_P35, BANAN_9_P36, BANAN_9_P37, BANAN_9_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  9号桩发送成功。\n");
	sleep(41);
	
	printf("正在发送四海线 —— 1号桩：\n");
	XsyjDate(SIHAI_1_IMSI, SIHAI_1_P33, SIHAI_1_P34, SIHAI_1_P35, SIHAI_1_P36, SIHAI_1_P37, SIHAI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("四海线 ——  1号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 12号桩：\n");
	XsyjDate(BANAN_12_IMSI, BANAN_12_P33, BANAN_12_P34, BANAN_12_P35, BANAN_12_P36, BANAN_12_P37, BANAN_12_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  12号桩发送成功。\n");
	sleep(54);
	
	printf("正在发送上长线 —— 4号桩：\n");
	XsyjDate(SHANGCHANG_4_IMSI, SHANGCHANG_4_P33, SHANGCHANG_4_P34, SHANGCHANG_4_P35, SHANGCHANG_4_P36, SHANGCHANG_4_P37, SHANGCHANG_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("上长线 ——  4号桩发送成功。\n");
	sleep(2);
	
	printf("正在发送长安线 —— 2号桩：\n");
	XsyjDate(CHANGAN_2_IMSI, CHANGAN_2_P33, CHANGAN_2_P34, CHANGAN_2_P35, CHANGAN_2_P36, CHANGAN_2_P37, CHANGAN_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("长安线 ——  2号桩发送成功。\n");
	sleep(21);
	
	printf("正在发送伍桂线 —— 果树园：\n");
	XsyjDate(WUGUI_GSY_IMSI, WUGUI_GSY_P33, WUGUI_GSY_P34, WUGUI_GSY_P35, WUGUI_GSY_P36, WUGUI_GSY_P37, WUGUI_GSY_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("伍桂线 ——  果树园发送成功。\n");
	sleep(26);
	
	printf("正在发送人头线 —— 2号桩：\n");
	XsyjDate(RENTOU_2_IMSI, RENTOU_2_P33, RENTOU_2_P34, RENTOU_2_P35, RENTOU_2_P36, RENTOU_2_P37, RENTOU_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("人头线 ——  2号桩发送成功。\n");
	sleep(12);
	
	printf("正在发送四茶线 —— 7号桩：\n");
	XsyjDate(SICAI_7_IMSI, SICAI_7_P33, SICAI_7_P34, SICAI_7_P35, SICAI_7_P36, SICAI_7_P37, SICAI_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("四茶线 ——  7号桩发送成功。\n");
	sleep(19);
	
	
	
	
	
	printf("正在发送外环巴南段 —— 13号桩：\n");
	XsyjDate(BANAN_13_IMSI, BANAN_13_P33, BANAN_13_P34, BANAN_13_P35, BANAN_13_P36, BANAN_13_P37, BANAN_13_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  13号桩发送成功。\n");
	sleep(14);
	
	printf("正在发送外环巴南段 —— 1号桩：\n");
	XsyjDate(BANAN_1_IMSI, BANAN_1_P33, BANAN_1_P34, BANAN_1_P35, BANAN_1_P36, BANAN_1_P37, BANAN_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  1号桩发送成功。\n");
	sleep(42);
	
	printf("正在发送外环巴南段 —— 5号桩：\n");
	XsyjDate(BANAN_5_IMSI, BANAN_5_P33, BANAN_5_P34, BANAN_5_P35, BANAN_5_P36, BANAN_5_P37, BANAN_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  5号桩发送成功。\n");
	sleep(11);
	
	printf("正在发送四七线 —— 7号桩：\n");
	XsyjDate(SIQI_7_IMSI, SIQI_7_P33, SIQI_7_P34, SIQI_7_P35, SIQI_7_P36, SIQI_7_P37, SIQI_7_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("四七线 ——  7号桩发送成功。\n");
	sleep(26);
	
	printf("正在发送外环巴南段 —— 8号桩：\n");
	XsyjDate(BANAN_8_IMSI, BANAN_8_P33, BANAN_8_P34, BANAN_8_P35, BANAN_8_P36, BANAN_8_P37, BANAN_8_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  8号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送长安线 —— 4号桩：\n");
	XsyjDate(CHANGAN_4_IMSI, CHANGAN_4_P33, CHANGAN_4_P34, CHANGAN_4_P35, CHANGAN_4_P36, CHANGAN_4_P37, CHANGAN_4_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("长安线 ——  4号桩发送成功。\n");
	sleep(41);
	
	printf("正在发送造纸线 —— 2号桩：\n");
	XsyjDate(ZAOZHI_2_IMSI, ZAOZHI_2_P33, ZAOZHI_2_P34, ZAOZHI_2_P35, ZAOZHI_2_P36, ZAOZHI_2_P37, ZAOZHI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("造纸线 ——  2号桩发送成功。\n");
	sleep(8);
	
	printf("正在发送伍桂线 —— 钢材市场旁：\n");
	XsyjDate(WUGUI_GCS_IMSI, WUGUI_GCS_P33, WUGUI_GCS_P34, WUGUI_GCS_P35, WUGUI_GCS_P36, WUGUI_GCS_P37, WUGUI_GCS_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("伍桂线 ——  钢材市场旁发送成功。\n");
	sleep(16);
	
	printf("正在发送人头线 —— 5号桩：\n");
	XsyjDate(RENTOU_5_IMSI, RENTOU_5_P33, RENTOU_5_P34, RENTOU_5_P35, RENTOU_5_P36, RENTOU_5_P37, RENTOU_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("人头线 ——  5号桩发送成功。\n");
	sleep(24);
	
	printf("正在发送外环巴南段 —— 6号桩：\n");
	XsyjDate(BANAN_6_IMSI, BANAN_6_P33, BANAN_6_P34, BANAN_6_P35, BANAN_6_P36, BANAN_6_P37, BANAN_6_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  6号桩发送成功。\n");
	sleep(42);
	
	printf("正在发送外环巴南段 —— 18号桩：\n");
	XsyjDate(BANAN_18_IMSI, BANAN_18_P33, BANAN_18_P34, BANAN_18_P35, BANAN_18_P36, BANAN_18_P37, BANAN_18_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  18号桩发送成功。\n");
	sleep(30);
	
	printf("正在发送伍桂线 —— 报废汽车回收站旁：\n");
	XsyjDate(WUGUI_BFQ_IMSI, WUGUI_BFQ_P33, WUGUI_BFQ_P34, WUGUI_BFQ_P35, WUGUI_BFQ_P36, WUGUI_BFQ_P37, WUGUI_BFQ_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("伍桂线 ——  报废汽车回收站旁发送成功。\n");
	sleep(20);

	printf("正在发送外环巴南段 —— 2号桩：\n");
	XsyjDate(BANAN_2_IMSI, BANAN_2_P33, BANAN_2_P34, BANAN_2_P35, BANAN_2_P36, BANAN_2_P37, BANAN_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  2号桩发送成功。\n");
	sleep(15);
	
	
	printf("正在发送四海线 —— 3号桩：\n");
	XsyjDate(SIHAI_3_IMSI, SIHAI_3_P33, SIHAI_3_P34, SIHAI_3_P35, SIHAI_3_P36, SIHAI_3_P37, SIHAI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("四海线 ——  3号桩发送成功。\n");
	sleep(45);
	
	printf("正在发送外环巴南段 —— 10号桩：\n");
	XsyjDate(BANAN_10_IMSI, BANAN_10_P33, BANAN_10_P34, BANAN_10_P35, BANAN_10_P36, BANAN_10_P37, BANAN_10_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("外环巴南段 ——  10号桩发送成功。\n");
	sleep(1);

	printf("正在发送茶园迎龙线 —— 5号桩：\n");
	XsyjDate(CAIYUAN_5_IMSI, CAIYUAN_5_P33, CAIYUAN_5_P34, CAIYUAN_5_P35, CAIYUAN_5_P36, CAIYUAN_5_P37, CAIYUAN_5_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 5号桩发送成功。\n");
	sleep(21);

	printf("正在发送茶园迎龙线 —— 8号桩：\n");
	XsyjDate(CAIYUAN_8_IMSI, CAIYUAN_8_P33, CAIYUAN_8_P34, CAIYUAN_8_P35, CAIYUAN_8_P36, CAIYUAN_8_P37, CAIYUAN_8_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 8号桩发送成功。\n");
	sleep(11);

	printf("正在发送茶园迎龙线 —— 10号桩：\n");
	XsyjDate(CAIYUAN_10_IMSI, CAIYUAN_10_P33, CAIYUAN_10_P34, CAIYUAN_10_P35, CAIYUAN_10_P36, CAIYUAN_10_P37, CAIYUAN_10_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 10号桩发送成功。\n");
	sleep(15);

	printf("正在发送茶园迎龙线 —— 426号桩：\n");
	XsyjDate(CAIYUAN_426_IMSI, CAIYUAN_426_P33, CAIYUAN_426_P34, CAIYUAN_426_P35, CAIYUAN_426_P36, CAIYUAN_426_P37, CAIYUAN_426_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 426号桩发送成功。\n");
	sleep(15);

	printf("正在发送实验线 —— 1号桩：\n");
	XsyjDate(YANSHI_1_IMSI, YANSHI_1_P33, YANSHI_1_P34, YANSHI_1_P35, YANSHI_1_P36, YANSHI_1_P37, YANSHI_1_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("实验线 —— 1号桩发送成功。\n");
	sleep(13);

	printf("正在发送实验线 —— 2号桩：\n");
	XsyjDate(YANSHI_2_IMSI, YANSHI_2_P33, YANSHI_2_P34, YANSHI_2_P35, YANSHI_2_P36, YANSHI_2_P37, YANSHI_2_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("实验线 —— 2号桩发送成功。\n");
	sleep(33);

	printf("正在发送实验线 —— 3号桩：\n");
	XsyjDate(YANSHI_3_IMSI, YANSHI_3_P33, YANSHI_3_P34, YANSHI_3_P35, YANSHI_3_P36, YANSHI_3_P37, YANSHI_3_P38);
	send(sock_fd, g_dataBuf, 50, 0);
	printf("实验线 —— 3号桩发送成功。\n");
	sleep(20);
#endif                                    /* QZDL */
}