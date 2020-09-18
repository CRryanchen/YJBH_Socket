#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <unistd.h>
#include <time.h>
#include "global.h"

#define PORT       5400	                  		/*!< �˿� */                 
#define IP_ADDRESS "118.24.246.188" 		/*!< ������IP��ַ */            
#define QZDZ		                      		/*!< �������������ǿ�Ƶ������������������� */


void  QZDL_Data         (char * imsi, float p34,     float p36, float p37, float p8);
void  XSYJ_Data         (char * imsi              , float p33, float p34, float p35, float p36, float p37, float p8);
void  QZDL_Print        (unsigned char imsi_temp[], float p34, float p36, float p37, float p38);
void  PrintHead         (unsigned char type);
void  PrintImsi         (char * imsi);
void  PrintCRC          (unsigned char type);

void  XSYJ_Print        (unsigned char imsi_temp[], float p33, float p34, float p35, float p36, float p37, float p38);
void  PrintParam        (float p                  , int para, unsigned char type);
float RandomParam       (float p);
float CurrentRandomParam(float p);

unsigned char DataBuf[50];

void SendDataToServer(SOCKET sock_fd)
{
#if defined QZDL

	printf("���ڷ��Ͱ����� ���� 3��׮��\n");
	QZDL_Data(BAIZI_3_IMSI, BAIZI_3_P34, BAIZI_3_P36, BAIZI_3_P37, BAIZI_3_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  3��׮���ͳɹ���\n");
	sleep(17);
	
	printf("���ڷ��Ͱ����� ���� 12��׮��\n");
	QZDL_Data(BAIZI_12_IMSI, BAIZI_12_P34, BAIZI_12_P36, BAIZI_12_P37, BAIZI_12_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  12��׮���ͳɹ���\n");
	sleep(56);
	
	printf("���ڷ��Ͱ����� ���� 4��׮��\n");
	QZDL_Data(ANLAN_4_IMSI, ANLAN_4_P34, ANLAN_4_P36, ANLAN_4_P37, ANLAN_4_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(18);
	
	printf("���ڷ��Ͱ����� ���� 1��׮��\n");
	QZDL_Data(BAIZI_1_IMSI, BAIZI_1_P34, BAIZI_1_P36, BAIZI_1_P37, BAIZI_1_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(31);
	
	
	printf("���ڷ��Ͱ����� ���� 3��׮��\n");
	QZDL_Data(ANLAN_3_IMSI, ANLAN_3_P34, ANLAN_3_P36, ANLAN_3_P37, ANLAN_3_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  3��׮���ͳɹ���\n");
	sleep(49);
	
	printf("���ڷ��Ͱ����� ���� 16��׮��\n");
	QZDL_Data(BAIZI_16_IMSI, BAIZI_16_P34, BAIZI_16_P36, BAIZI_16_P37, BAIZI_16_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  16��׮���ͳɹ���\n");
	sleep(17);
	
	printf("���ڷ��Ͱ����� ���� 1��׮��\n");
	QZDL_Data(ANLAN_1_IMSI, ANLAN_1_P34, ANLAN_1_P36, ANLAN_1_P37, ANLAN_1_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(22);
	
	printf("���ڷ��Ͱ����� ���� 14��׮��\n");
	QZDL_Data(BAIZI_14_IMSI, BAIZI_14_P34, BAIZI_14_P36, BAIZI_14_P37, BAIZI_14_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  14��׮���ͳɹ���\n");
	sleep(28);
	
	printf("���ڷ��Ͱ����� ���� 15��׮��\n");
	QZDL_Data(BAIZI_15_IMSI, BAIZI_15_P34, BAIZI_15_P36, BAIZI_15_P37, BAIZI_15_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  15��׮���ͳɹ���\n");
	sleep(32);

	printf("���ڷ��Ͱ����� ���� 10��׮��\n");
	QZDL_Data(BAIZI_10_IMSI, BAIZI_10_P34, BAIZI_10_P36, BAIZI_10_P37, BAIZI_10_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  10��׮���ͳɹ���\n");
	sleep(33);

	printf("���ڷ��Ͱ����� ���� 8��׮��\n");
	QZDL_Data(BAIZI_8_IMSI, BAIZI_8_P34, BAIZI_8_P36, BAIZI_8_P37, BAIZI_8_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  8��׮���ͳɹ���\n");
	sleep(66);
	
	printf("���ڷ��Ͱ����� ���� 7��׮��\n");
	QZDL_Data(BAIZI_7_IMSI, BAIZI_7_P34, BAIZI_7_P36, BAIZI_7_P37, BAIZI_7_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  7��׮���ͳɹ���\n");
	sleep(43);
	
	printf("���ڷ��Ͱ����� ���� 5��׮��\n");
	QZDL_Data(BAIZI_5_IMSI, BAIZI_5_P34, BAIZI_5_P36, BAIZI_5_P37, BAIZI_5_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  5��׮���ͳɹ���\n");
	sleep(21);
	
	printf("���ڷ��Ͱ����� ���� 17��׮��\n");
	QZDL_Data(BAIZI_17_IMSI, BAIZI_17_P34, BAIZI_17_P36, BAIZI_17_P37, BAIZI_17_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  17��׮���ͳɹ���\n");
	sleep(11);
	
	printf("���ڷ��Ͱ����� ���� 5��׮��\n");
	QZDL_Data(ANLAN_5_IMSI, ANLAN_5_P34, ANLAN_5_P36, ANLAN_5_P37, ANLAN_5_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  5��׮���ͳɹ���\n");
	sleep(28);
	
	printf("���ڷ��Ͱ����� ���� 4��׮��\n");
	QZDL_Data(BAIZI_4_IMSI, BAIZI_4_P34, BAIZI_4_P36, BAIZI_4_P37, BAIZI_4_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(61);

	printf("���ڷ��Ͱ����� ���� 9��׮��\n");
	QZDL_Data(BAIZI_9_IMSI, BAIZI_9_P34, BAIZI_9_P36, BAIZI_9_P37, BAIZI_9_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("������ ����  9��׮���ͳɹ���\n");
	sleep(12);

#else
	printf("���ڷ����⻷���϶� ���� 15��׮��\n");
	XSYJ_Data(BANAN_15_IMSI, BANAN_15_P33, BANAN_15_P34, BANAN_15_P35, BANAN_15_P36, BANAN_15_P37, BANAN_15_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  15��׮���ͳɹ���\n");
	sleep(13);
	
	printf("���ڷ����⻷���϶� ���� 16��׮��\n");
	XSYJ_Data(BANAN_16_IMSI, BANAN_16_P33, BANAN_16_P34, BANAN_16_P35, BANAN_16_P36, BANAN_16_P37, BANAN_16_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  16��׮���ͳɹ���\n");
	sleep(25);
	
	
	
	printf("���ڷ�����ͷ�� ���� 7��׮��\n");
	XSYJ_Data(RENTOU_7_IMSI, RENTOU_7_P33, RENTOU_7_P34, RENTOU_7_P35, RENTOU_7_P36, RENTOU_7_P37, RENTOU_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ͷ�� ����  7��׮���ͳɹ���\n");
	sleep(38);
	
	
	
	printf("���ڷ��ͺ����� ���� 17��׮��\n");
	XSYJ_Data(HANWANG_17_IMSI, HANWANG_17_P33, HANWANG_17_P34, HANWANG_17_P35, HANWANG_17_P36, HANWANG_17_P37, HANWANG_17_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  17��׮���ͳɹ���\n");
	sleep(4);
	
	printf("���ڷ����⻷���϶� ���� 14��׮��\n");
	XSYJ_Data(BANAN_14_IMSI, BANAN_14_P33, BANAN_14_P34, BANAN_14_P35, BANAN_14_P36, BANAN_14_P37, BANAN_14_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  14��׮���ͳɹ���\n");
	sleep(35);
	
	printf("���ڷ����⻷���϶� ���� 11��׮��\n");
	XSYJ_Data(BANAN_11_IMSI, BANAN_11_P33, BANAN_11_P34, BANAN_11_P35, BANAN_11_P36, BANAN_11_P37, BANAN_11_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  11��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 17��׮��\n");
	XSYJ_Data(BANAN_17_IMSI, BANAN_17_P33, BANAN_17_P34, BANAN_17_P35, BANAN_17_P36, BANAN_17_P37, BANAN_17_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  17��׮���ͳɹ���\n");
	sleep(54);
	
	printf("���ڷ����ϳ��� ���� 5��׮��\n");
	XSYJ_Data(SHANGCHANG_5_IMSI, SHANGCHANG_5_P33, SHANGCHANG_5_P34, SHANGCHANG_5_P35, SHANGCHANG_5_P36, SHANGCHANG_5_P37, SHANGCHANG_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�ϳ��� ����  5��׮���ͳɹ���\n");
	sleep(32);
	
	printf("���ڷ��ͳ����� ���� 1��׮��\n");
	XSYJ_Data(CHANGAN_1_IMSI, CHANGAN_1_P33, CHANGAN_1_P34, CHANGAN_1_P35, CHANGAN_1_P36, CHANGAN_1_P37, CHANGAN_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  1��׮���ͳɹ���\n");
	sleep(12);
	
	printf("���ڷ�����ֽ�� ���� 3��׮��\n");
	XSYJ_Data(ZAOZHI_3_IMSI, ZAOZHI_3_P33, ZAOZHI_3_P34, ZAOZHI_3_P35, ZAOZHI_3_P36, ZAOZHI_3_P37, ZAOZHI_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ֽ�� ����  3��׮���ͳɹ���\n");
	sleep(43);
	
	printf("���ڷ��������� ���� 2��׮��\n");
	XSYJ_Data(SIQI_2_IMSI, SIQI_2_P33, SIQI_2_P34, SIQI_2_P35, SIQI_2_P36, SIQI_2_P37, SIQI_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  2��׮���ͳɹ���\n");
	sleep(25);
	
	printf("���ڷ����⻷���϶� ���� 4��׮��\n");
	XSYJ_Data(BANAN_4_IMSI, BANAN_4_P33, BANAN_4_P34, BANAN_4_P35, BANAN_4_P36, BANAN_4_P37, BANAN_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  4��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ�������� ���� �Ƽ����ɳ�����\n");
	XSYJ_Data(WUGUI_TJT_IMSI, WUGUI_TJT_P33, WUGUI_TJT_P34, WUGUI_TJT_P35, WUGUI_TJT_P36, WUGUI_TJT_P37, WUGUI_TJT_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("����� ����  �Ƽ����ɳ������ͳɹ���\n");
	sleep(1);
	
	
	
	
	printf("���ڷ��ͺ����� ���� 16��׮��\n");
	XSYJ_Data(HANWANG_16_IMSI, HANWANG_16_P33, HANWANG_16_P34, HANWANG_16_P35, HANWANG_16_P36, HANWANG_16_P37, HANWANG_16_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  16��׮���ͳɹ���\n");
	sleep(43);
	
	
	printf("���ڷ����⻷���϶� ���� 3��׮��\n");
	XSYJ_Data(BANAN_3_IMSI, BANAN_3_P33, BANAN_3_P34, BANAN_3_P35, BANAN_3_P36, BANAN_3_P37, BANAN_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  3��׮���ͳɹ���\n");
	sleep(44);
	
	
	
	printf("���ڷ�����ֽ�� ���� 1��׮��\n");
	XSYJ_Data(ZAOZHI_1_IMSI, ZAOZHI_1_P33, ZAOZHI_1_P34, ZAOZHI_1_P35, ZAOZHI_1_P36, ZAOZHI_1_P37, ZAOZHI_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ֽ�� ����  1��׮���ͳɹ���\n");
	sleep(17);
	
	
	
	printf("���ڷ����⻷���϶� ���� 7��׮��\n");
	XSYJ_Data(BANAN_7_IMSI, BANAN_7_P33, BANAN_7_P34, BANAN_7_P35, BANAN_7_P36, BANAN_7_P37, BANAN_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  7��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 9��׮��\n");
	XSYJ_Data(BANAN_9_IMSI, BANAN_9_P33, BANAN_9_P34, BANAN_9_P35, BANAN_9_P36, BANAN_9_P37, BANAN_9_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  9��׮���ͳɹ���\n");
	sleep(41);
	
	printf("���ڷ����ĺ��� ���� 1��׮��\n");
	XSYJ_Data(SIHAI_1_IMSI, SIHAI_1_P33, SIHAI_1_P34, SIHAI_1_P35, SIHAI_1_P36, SIHAI_1_P37, SIHAI_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�ĺ��� ����  1��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ����⻷���϶� ���� 12��׮��\n");
	XSYJ_Data(BANAN_12_IMSI, BANAN_12_P33, BANAN_12_P34, BANAN_12_P35, BANAN_12_P36, BANAN_12_P37, BANAN_12_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  12��׮���ͳɹ���\n");
	sleep(54);
	
	printf("���ڷ����ϳ��� ���� 4��׮��\n");
	XSYJ_Data(SHANGCHANG_4_IMSI, SHANGCHANG_4_P33, SHANGCHANG_4_P34, SHANGCHANG_4_P35, SHANGCHANG_4_P36, SHANGCHANG_4_P37, SHANGCHANG_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�ϳ��� ����  4��׮���ͳɹ���\n");
	sleep(2);
	
	printf("���ڷ��ͳ����� ���� 2��׮��\n");
	XSYJ_Data(CHANGAN_2_IMSI, CHANGAN_2_P33, CHANGAN_2_P34, CHANGAN_2_P35, CHANGAN_2_P36, CHANGAN_2_P37, CHANGAN_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  2��׮���ͳɹ���\n");
	sleep(21);
	
	printf("���ڷ�������� ���� ����԰��\n");
	XSYJ_Data(WUGUI_GSY_IMSI, WUGUI_GSY_P33, WUGUI_GSY_P34, WUGUI_GSY_P35, WUGUI_GSY_P36, WUGUI_GSY_P37, WUGUI_GSY_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("����� ����  ����԰���ͳɹ���\n");
	sleep(26);
	
	printf("���ڷ�����ͷ�� ���� 2��׮��\n");
	XSYJ_Data(RENTOU_2_IMSI, RENTOU_2_P33, RENTOU_2_P34, RENTOU_2_P35, RENTOU_2_P36, RENTOU_2_P37, RENTOU_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ͷ�� ����  2��׮���ͳɹ���\n");
	sleep(12);
	
	printf("���ڷ����Ĳ��� ���� 7��׮��\n");
	XSYJ_Data(SICAI_7_IMSI, SICAI_7_P33, SICAI_7_P34, SICAI_7_P35, SICAI_7_P36, SICAI_7_P37, SICAI_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�Ĳ��� ����  7��׮���ͳɹ���\n");
	sleep(19);
	
	
	
	
	
	printf("���ڷ����⻷���϶� ���� 13��׮��\n");
	XSYJ_Data(BANAN_13_IMSI, BANAN_13_P33, BANAN_13_P34, BANAN_13_P35, BANAN_13_P36, BANAN_13_P37, BANAN_13_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  13��׮���ͳɹ���\n");
	sleep(14);
	
	
	
	printf("���ڷ����⻷���϶� ���� 1��׮��\n");
	XSYJ_Data(BANAN_1_IMSI, BANAN_1_P33, BANAN_1_P34, BANAN_1_P35, BANAN_1_P36, BANAN_1_P37, BANAN_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  1��׮���ͳɹ���\n");
	sleep(42);
	
	
	
	printf("���ڷ����⻷���϶� ���� 5��׮��\n");
	XSYJ_Data(BANAN_5_IMSI, BANAN_5_P33, BANAN_5_P34, BANAN_5_P35, BANAN_5_P36, BANAN_5_P37, BANAN_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  5��׮���ͳɹ���\n");
	sleep(11);
	
	printf("���ڷ��������� ���� 7��׮��\n");
	XSYJ_Data(SIQI_7_IMSI, SIQI_7_P33, SIQI_7_P34, SIQI_7_P35, SIQI_7_P36, SIQI_7_P37, SIQI_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  7��׮���ͳɹ���\n");
	sleep(26);
	
	printf("���ڷ����⻷���϶� ���� 8��׮��\n");
	XSYJ_Data(BANAN_8_IMSI, BANAN_8_P33, BANAN_8_P34, BANAN_8_P35, BANAN_8_P36, BANAN_8_P37, BANAN_8_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  8��׮���ͳɹ���\n");
	sleep(23);
	
	printf("���ڷ��ͳ����� ���� 4��׮��\n");
	XSYJ_Data(CHANGAN_4_IMSI, CHANGAN_4_P33, CHANGAN_4_P34, CHANGAN_4_P35, CHANGAN_4_P36, CHANGAN_4_P37, CHANGAN_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("������ ����  4��׮���ͳɹ���\n");
	sleep(41);
	
	printf("���ڷ�����ֽ�� ���� 2��׮��\n");
	XSYJ_Data(ZAOZHI_2_IMSI, ZAOZHI_2_P33, ZAOZHI_2_P34, ZAOZHI_2_P35, ZAOZHI_2_P36, ZAOZHI_2_P37, ZAOZHI_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ֽ�� ����  2��׮���ͳɹ���\n");
	sleep(8);
	
	printf("���ڷ�������� ���� �ֲ��г��ԣ�\n");
	XSYJ_Data(WUGUI_GCS_IMSI, WUGUI_GCS_P33, WUGUI_GCS_P34, WUGUI_GCS_P35, WUGUI_GCS_P36, WUGUI_GCS_P37, WUGUI_GCS_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("����� ����  �ֲ��г��Է��ͳɹ���\n");
	sleep(16);
	
	printf("���ڷ�����ͷ�� ���� 5��׮��\n");
	XSYJ_Data(RENTOU_5_IMSI, RENTOU_5_P33, RENTOU_5_P34, RENTOU_5_P35, RENTOU_5_P36, RENTOU_5_P37, RENTOU_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("��ͷ�� ����  5��׮���ͳɹ���\n");
	sleep(24);
	
	
	
	
	
	
	
	printf("���ڷ����⻷���϶� ���� 6��׮��\n");
	XSYJ_Data(BANAN_6_IMSI, BANAN_6_P33, BANAN_6_P34, BANAN_6_P35, BANAN_6_P36, BANAN_6_P37, BANAN_6_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  6��׮���ͳɹ���\n");
	sleep(42);
	
	printf("���ڷ����⻷���϶� ���� 18��׮��\n");
	XSYJ_Data(BANAN_18_IMSI, BANAN_18_P33, BANAN_18_P34, BANAN_18_P35, BANAN_18_P36, BANAN_18_P37, BANAN_18_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  18��׮���ͳɹ���\n");
	sleep(30);
	
	printf("���ڷ�������� ���� ������������վ�ԣ�\n");
	XSYJ_Data(WUGUI_BFQ_IMSI, WUGUI_BFQ_P33, WUGUI_BFQ_P34, WUGUI_BFQ_P35, WUGUI_BFQ_P36, WUGUI_BFQ_P37, WUGUI_BFQ_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("����� ����  ������������վ�Է��ͳɹ���\n");
	sleep(20);

	printf("���ڷ����⻷���϶� ���� 2��׮��\n");
	XSYJ_Data(BANAN_2_IMSI, BANAN_2_P33, BANAN_2_P34, BANAN_2_P35, BANAN_2_P36, BANAN_2_P37, BANAN_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  2��׮���ͳɹ���\n");
	sleep(15);
	
	
	printf("���ڷ����ĺ��� ���� 3��׮��\n");
	XSYJ_Data(SIHAI_3_IMSI, SIHAI_3_P33, SIHAI_3_P34, SIHAI_3_P35, SIHAI_3_P36, SIHAI_3_P37, SIHAI_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�ĺ��� ����  3��׮���ͳɹ���\n");
	sleep(45);
	
	printf("���ڷ����⻷���϶� ���� 10��׮��\n");
	XSYJ_Data(BANAN_10_IMSI, BANAN_10_P33, BANAN_10_P34, BANAN_10_P35, BANAN_10_P36, BANAN_10_P37, BANAN_10_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("�⻷���϶� ����  10��׮���ͳɹ���\n");
	sleep(1);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 5��׮��\n");
	XSYJ_Data(CAIYUAN_5_IMSI, CAIYUAN_5_P33, CAIYUAN_5_P34, CAIYUAN_5_P35, CAIYUAN_5_P36, CAIYUAN_5_P37, CAIYUAN_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 5��׮���ͳɹ���\n");
	sleep(21);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 8��׮��\n");
	XSYJ_Data(CAIYUAN_8_IMSI, CAIYUAN_8_P33, CAIYUAN_8_P34, CAIYUAN_8_P35, CAIYUAN_8_P36, CAIYUAN_8_P37, CAIYUAN_8_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 8��׮���ͳɹ���\n");
	sleep(11);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 10��׮��\n");
	XSYJ_Data(CAIYUAN_10_IMSI, CAIYUAN_10_P33, CAIYUAN_10_P34, CAIYUAN_10_P35, CAIYUAN_10_P36, CAIYUAN_10_P37, CAIYUAN_10_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 10��׮���ͳɹ���\n");
	sleep(15);

	printf("���ڷ��Ͳ�԰ӭ���� ���� 426��׮��\n");
	XSYJ_Data(CAIYUAN_426_IMSI, CAIYUAN_426_P33, CAIYUAN_426_P34, CAIYUAN_426_P35, CAIYUAN_426_P36, CAIYUAN_426_P37, CAIYUAN_426_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("���ڷ��Ͳ�԰ӭ���� ���� 426��׮���ͳɹ���\n");
	sleep(15);

#endif                                    /* QZDL */
}


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


// ��������

void QZDL_Data(char * imsi, float p34, float p36, float p37, float p38)
{
	unsigned char imsi_temp[20];
	strcpy(imsi_temp, imsi);
	QZDL_Print(imsi_temp, p34, p36, p37, p38);
}


void XSYJ_Data(char * imsi, float p33, float p34, float p35, float p36, float p37, float p38)
{
	unsigned char imsi_temp[20];
	strcpy(imsi_temp, imsi);
	XSYJ_Print(imsi_temp, p33, p34, p35, p36, p37, p38);
}


// ��ӡͷ�� 2���ֽ�
void PrintHead(unsigned char type)
{
	if (1 == type)
	{
		DataBuf[0] = 50;
	}
	else
	{
		DataBuf[0] = 38;
	}
	DataBuf[1] = 3;
}

// ��ӡIMSI�� 4���ֽ�
void PrintImsi(char * imsi)
{
	int imsi_1;
	int imsi_2;
	int imsi_3;
	int imsi_4;
	
	sscanf(imsi, "%3d", &imsi_1);
	sscanf(imsi + 3, "%4d", &imsi_2);
	sscanf(imsi + 7, "%4d", &imsi_3);
	sscanf(imsi + 11, "%4d", &imsi_4);
	DataBuf[2] = (unsigned char)((imsi_1 >> 8) & 0XFF);
	DataBuf[3] = (unsigned char)(imsi_1 & 0XFF);
	
	DataBuf[4] = (imsi_2 >> 8) & 0XFF;
	DataBuf[5] = imsi_2 & 0XFF;
	
	DataBuf[6] = (imsi_3 >> 8) & 0XFF;
	DataBuf[7] = imsi_3 & 0XFF;

	DataBuf[8] = (imsi_4 >> 8) & 0XFF;
	DataBuf[9] = imsi_4 & 0XFF;
}

// ��ӡ��λ��
void PrintWorkNum(void)
{
	DataBuf[10] = 0;
	DataBuf[11] = 1;
}

// ��ӡCRCУ���
void PrintCRC(unsigned char type)
{
	if (1 == type)
	{
		DataBuf[48] = 0xff;
		DataBuf[49] = 0xff;
	}
	else
	{
		DataBuf[36] = 0xff;
		DataBuf[37] = 0xff;
	}
	
}



// ǿ�Ƶ����� ��4������
void QZDL_Print(unsigned char imsi_temp[], float p34, float p36, float p37, float p38)
{	

	p34 = RandomParam(p34);
	p36 = RandomParam(p36);
	p37 = RandomParam(p37);
	p38 = RandomParam(p38);


	PrintHead(0);
	PrintImsi(imsi_temp);
	PrintWorkNum();

	DataBuf[12] = 0X34;
	PrintParam(p34, 34, 0);
	printf("\t\t�ϵ��λΪ: %.3f\n", p34);
	
	DataBuf[18] = 0X36;
	PrintParam(p36, 36, 0);
	printf("\t\t��Ȼ��λΪ: %.3f\n", p36);
	
	DataBuf[24] = 0x37;
	PrintParam(p37, 37, 0);
	printf("\t\t��ص�ѹΪ: %.3f\n", p37);
	
	DataBuf[30] = 0X38;
	PrintParam(p38, 38, 0);
	printf("\t\tͨ���λΪ: %.3f\n", p38);
	
	PrintCRC(0);
}



// ������������ ��6������
void XSYJ_Print(unsigned char imsi_temp[], float p33, float p34, float p35, float p36, float p37, float p38)
{
	
	p33 = RandomParam(p33);
	p34 = RandomParam(p34);
	p35 = CurrentRandomParam(p35);
	p36 = RandomParam(p36);
	p37 = RandomParam(p37);
	p38 = RandomParam(p38);
	
	PrintHead(1);
	PrintImsi(imsi_temp);
	PrintWorkNum();
	
	DataBuf[12] = 0X33;
	PrintParam(p33, 33, 1);
	printf("\t\t��·��λΪ: %.3f\n", p33);
	
	DataBuf[18] = 0X34;
	PrintParam(p34, 34, 1);
	printf("\t\t�ϵ��λΪ: %.3f\n", p34);
	
	DataBuf[24] = 0X35;
	PrintParam(p35, 35, 1);
	printf("\t\t��������Ϊ: %.3f\n", p35);
	
	DataBuf[30] = 0X36;
	PrintParam(p36, 36, 1);
	printf("\t\t��Ȼ��λΪ: %.3f\n", p36);
	
	DataBuf[36] = 0x37;
	PrintParam(p37, 37, 1);
	printf("\t\t��ص�ѹΪ: %.3f\n", p37);
	
	DataBuf[42] = 0X38;
	PrintParam(p38, 38, 1);
	printf("\t\tͨ���λΪ: %.3f\n", p38);
	
	PrintCRC(1);
}

// ��ӡ����ֵ��5���ֽ�
void PrintParam(float p, int para, unsigned char type)
{
	unsigned char temp[4];
	memcpy(temp, (unsigned char *)&p, 4);
	
	switch(para)
	{
		case 33:
		{
			DataBuf[13] = (unsigned char)temp[3];
			DataBuf[14] = (unsigned char)temp[2];
			DataBuf[15] = (unsigned char)temp[1];
			DataBuf[16] = (unsigned char)temp[0];
			DataBuf[17] = (unsigned char)0;
		}
		break;
		
		case 34:
		{
			                                       // ��������
			if (1 == type)
			{
				DataBuf[19] = (unsigned char)temp[3];
				DataBuf[20] = (unsigned char)temp[2];
				DataBuf[21] = (unsigned char)temp[1];
				DataBuf[22] = (unsigned char)temp[0];
				DataBuf[23] = (unsigned char)0;
			}
			
			                                       // ǿ�Ƶ���
			else
			{
				DataBuf[13] = (unsigned char)temp[3];
				DataBuf[14] = (unsigned char)temp[2];
				DataBuf[15] = (unsigned char)temp[1];
				DataBuf[16] = (unsigned char)temp[0];
				DataBuf[17] = (unsigned char)0;
			}
		}
		break;
		
		case 35:
		{
			DataBuf[25] = (unsigned char)temp[3];
			DataBuf[26] = (unsigned char)temp[2];
			DataBuf[27] = (unsigned char)temp[1];
			DataBuf[28] = (unsigned char)temp[0];
			DataBuf[29] = (unsigned char)0;
		}
		break;
		
		case 36:
		{
			                                       // ��������
			if (1 == type)
			{
				DataBuf[31] = (unsigned char)temp[3];
				DataBuf[32] = (unsigned char)temp[2];
				DataBuf[33] = (unsigned char)temp[1];
				DataBuf[34] = (unsigned char)temp[0];
				DataBuf[35] = (unsigned char)0;
			}
			else
			{
				DataBuf[19] = (unsigned char)temp[3];
				DataBuf[20] = (unsigned char)temp[2];
				DataBuf[21] = (unsigned char)temp[1];
				DataBuf[22] = (unsigned char)temp[0];
				DataBuf[23] = (unsigned char)0;
			}
		}
		break;
		
		case 37:
		{
			                                       // ��������
			if (1 == type)
			{
				DataBuf[37] = (unsigned char)temp[3];
				DataBuf[38] = (unsigned char)temp[2];
				DataBuf[39] = (unsigned char)temp[1];
				DataBuf[40] = (unsigned char)temp[0];
				DataBuf[41] = (unsigned char)0;
			}
			else
			{
				DataBuf[25] = (unsigned char)temp[3];
				DataBuf[26] = (unsigned char)temp[2];
				DataBuf[27] = (unsigned char)temp[1];
				DataBuf[28] = (unsigned char)temp[0];
				DataBuf[29] = (unsigned char)0;	
			}
		}
		break;
		
		case 38:
		{
			                                       // ��������
			if (1 == type)
			{
				DataBuf[43] = (unsigned char)temp[3];
				DataBuf[44] = (unsigned char)temp[2];
				DataBuf[45] = (unsigned char)temp[1];
				DataBuf[46] = (unsigned char)temp[0];
				DataBuf[47] = (unsigned char)0;
			}
			else
			{
				DataBuf[31] = (unsigned char)temp[3];
				DataBuf[32] = (unsigned char)temp[2];
				DataBuf[33] = (unsigned char)temp[1];
				DataBuf[34] = (unsigned char)temp[0];
				DataBuf[35] = (unsigned char)0;
			}
		}
		break;
	}
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
