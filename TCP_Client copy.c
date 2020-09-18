#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <unistd.h>
#include <time.h>
#include "global.h"

#define PORT       5400	                  		/*!< 端口 */                 
#define IP_ADDRESS "118.24.246.188" 		/*!< 服务器IP地址 */            
#define QZDZ		                      		/*!< 这个宏用于区分强制电流还是牺牲阳极类型 */


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

	printf("正在发送白梓线 —— 3号桩：\n");
	QZDL_Data(BAIZI_3_IMSI, BAIZI_3_P34, BAIZI_3_P36, BAIZI_3_P37, BAIZI_3_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  3号桩发送成功。\n");
	sleep(17);
	
	printf("正在发送白梓线 —— 12号桩：\n");
	QZDL_Data(BAIZI_12_IMSI, BAIZI_12_P34, BAIZI_12_P36, BAIZI_12_P37, BAIZI_12_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  12号桩发送成功。\n");
	sleep(56);
	
	printf("正在发送安澜线 —— 4号桩：\n");
	QZDL_Data(ANLAN_4_IMSI, ANLAN_4_P34, ANLAN_4_P36, ANLAN_4_P37, ANLAN_4_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("安澜线 ——  4号桩发送成功。\n");
	sleep(18);
	
	printf("正在发送白梓线 —— 1号桩：\n");
	QZDL_Data(BAIZI_1_IMSI, BAIZI_1_P34, BAIZI_1_P36, BAIZI_1_P37, BAIZI_1_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  1号桩发送成功。\n");
	sleep(31);
	
	
	printf("正在发送安澜线 —— 3号桩：\n");
	QZDL_Data(ANLAN_3_IMSI, ANLAN_3_P34, ANLAN_3_P36, ANLAN_3_P37, ANLAN_3_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("安澜线 ——  3号桩发送成功。\n");
	sleep(49);
	
	printf("正在发送白梓线 —— 16号桩：\n");
	QZDL_Data(BAIZI_16_IMSI, BAIZI_16_P34, BAIZI_16_P36, BAIZI_16_P37, BAIZI_16_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  16号桩发送成功。\n");
	sleep(17);
	
	printf("正在发送安澜线 —— 1号桩：\n");
	QZDL_Data(ANLAN_1_IMSI, ANLAN_1_P34, ANLAN_1_P36, ANLAN_1_P37, ANLAN_1_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("安澜线 ——  1号桩发送成功。\n");
	sleep(22);
	
	printf("正在发送白梓线 —— 14号桩：\n");
	QZDL_Data(BAIZI_14_IMSI, BAIZI_14_P34, BAIZI_14_P36, BAIZI_14_P37, BAIZI_14_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  14号桩发送成功。\n");
	sleep(28);
	
	printf("正在发送白梓线 —— 15号桩：\n");
	QZDL_Data(BAIZI_15_IMSI, BAIZI_15_P34, BAIZI_15_P36, BAIZI_15_P37, BAIZI_15_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  15号桩发送成功。\n");
	sleep(32);

	printf("正在发送白梓线 —— 10号桩：\n");
	QZDL_Data(BAIZI_10_IMSI, BAIZI_10_P34, BAIZI_10_P36, BAIZI_10_P37, BAIZI_10_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  10号桩发送成功。\n");
	sleep(33);

	printf("正在发送白梓线 —— 8号桩：\n");
	QZDL_Data(BAIZI_8_IMSI, BAIZI_8_P34, BAIZI_8_P36, BAIZI_8_P37, BAIZI_8_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  8号桩发送成功。\n");
	sleep(66);
	
	printf("正在发送白梓线 —— 7号桩：\n");
	QZDL_Data(BAIZI_7_IMSI, BAIZI_7_P34, BAIZI_7_P36, BAIZI_7_P37, BAIZI_7_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  7号桩发送成功。\n");
	sleep(43);
	
	printf("正在发送白梓线 —— 5号桩：\n");
	QZDL_Data(BAIZI_5_IMSI, BAIZI_5_P34, BAIZI_5_P36, BAIZI_5_P37, BAIZI_5_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  5号桩发送成功。\n");
	sleep(21);
	
	printf("正在发送白梓线 —— 17号桩：\n");
	QZDL_Data(BAIZI_17_IMSI, BAIZI_17_P34, BAIZI_17_P36, BAIZI_17_P37, BAIZI_17_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  17号桩发送成功。\n");
	sleep(11);
	
	printf("正在发送安澜线 —— 5号桩：\n");
	QZDL_Data(ANLAN_5_IMSI, ANLAN_5_P34, ANLAN_5_P36, ANLAN_5_P37, ANLAN_5_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("安澜线 ——  5号桩发送成功。\n");
	sleep(28);
	
	printf("正在发送白梓线 —— 4号桩：\n");
	QZDL_Data(BAIZI_4_IMSI, BAIZI_4_P34, BAIZI_4_P36, BAIZI_4_P37, BAIZI_4_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  4号桩发送成功。\n");
	sleep(61);

	printf("正在发送白梓线 —— 9号桩：\n");
	QZDL_Data(BAIZI_9_IMSI, BAIZI_9_P34, BAIZI_9_P36, BAIZI_9_P37, BAIZI_9_P38);
	send(sock_fd, DataBuf, 38, 0);
	printf("白梓线 ——  9号桩发送成功。\n");
	sleep(12);

#else
	printf("正在发送外环巴南段 —— 15号桩：\n");
	XSYJ_Data(BANAN_15_IMSI, BANAN_15_P33, BANAN_15_P34, BANAN_15_P35, BANAN_15_P36, BANAN_15_P37, BANAN_15_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  15号桩发送成功。\n");
	sleep(13);
	
	printf("正在发送外环巴南段 —— 16号桩：\n");
	XSYJ_Data(BANAN_16_IMSI, BANAN_16_P33, BANAN_16_P34, BANAN_16_P35, BANAN_16_P36, BANAN_16_P37, BANAN_16_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  16号桩发送成功。\n");
	sleep(25);
	
	
	
	printf("正在发送人头线 —— 7号桩：\n");
	XSYJ_Data(RENTOU_7_IMSI, RENTOU_7_P33, RENTOU_7_P34, RENTOU_7_P35, RENTOU_7_P36, RENTOU_7_P37, RENTOU_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("人头线 ——  7号桩发送成功。\n");
	sleep(38);
	
	
	
	printf("正在发送旱望线 —— 17号桩：\n");
	XSYJ_Data(HANWANG_17_IMSI, HANWANG_17_P33, HANWANG_17_P34, HANWANG_17_P35, HANWANG_17_P36, HANWANG_17_P37, HANWANG_17_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("旱望线 ——  17号桩发送成功。\n");
	sleep(4);
	
	printf("正在发送外环巴南段 —— 14号桩：\n");
	XSYJ_Data(BANAN_14_IMSI, BANAN_14_P33, BANAN_14_P34, BANAN_14_P35, BANAN_14_P36, BANAN_14_P37, BANAN_14_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  14号桩发送成功。\n");
	sleep(35);
	
	printf("正在发送外环巴南段 —— 11号桩：\n");
	XSYJ_Data(BANAN_11_IMSI, BANAN_11_P33, BANAN_11_P34, BANAN_11_P35, BANAN_11_P36, BANAN_11_P37, BANAN_11_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  11号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 17号桩：\n");
	XSYJ_Data(BANAN_17_IMSI, BANAN_17_P33, BANAN_17_P34, BANAN_17_P35, BANAN_17_P36, BANAN_17_P37, BANAN_17_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  17号桩发送成功。\n");
	sleep(54);
	
	printf("正在发送上长线 —— 5号桩：\n");
	XSYJ_Data(SHANGCHANG_5_IMSI, SHANGCHANG_5_P33, SHANGCHANG_5_P34, SHANGCHANG_5_P35, SHANGCHANG_5_P36, SHANGCHANG_5_P37, SHANGCHANG_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("上长线 ——  5号桩发送成功。\n");
	sleep(32);
	
	printf("正在发送长安线 —— 1号桩：\n");
	XSYJ_Data(CHANGAN_1_IMSI, CHANGAN_1_P33, CHANGAN_1_P34, CHANGAN_1_P35, CHANGAN_1_P36, CHANGAN_1_P37, CHANGAN_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("长安线 ——  1号桩发送成功。\n");
	sleep(12);
	
	printf("正在发送造纸线 —— 3号桩：\n");
	XSYJ_Data(ZAOZHI_3_IMSI, ZAOZHI_3_P33, ZAOZHI_3_P34, ZAOZHI_3_P35, ZAOZHI_3_P36, ZAOZHI_3_P37, ZAOZHI_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("造纸线 ——  3号桩发送成功。\n");
	sleep(43);
	
	printf("正在发送四七线 —— 2号桩：\n");
	XSYJ_Data(SIQI_2_IMSI, SIQI_2_P33, SIQI_2_P34, SIQI_2_P35, SIQI_2_P36, SIQI_2_P37, SIQI_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("四七线 ——  2号桩发送成功。\n");
	sleep(25);
	
	printf("正在发送外环巴南段 —— 4号桩：\n");
	XSYJ_Data(BANAN_4_IMSI, BANAN_4_P33, BANAN_4_P34, BANAN_4_P35, BANAN_4_P36, BANAN_4_P37, BANAN_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  4号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送伍桂线 —— 唐家沱派出所：\n");
	XSYJ_Data(WUGUI_TJT_IMSI, WUGUI_TJT_P33, WUGUI_TJT_P34, WUGUI_TJT_P35, WUGUI_TJT_P36, WUGUI_TJT_P37, WUGUI_TJT_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("伍桂线 ——  唐家沱派出所发送成功。\n");
	sleep(1);
	
	
	
	
	printf("正在发送旱望线 —— 16号桩：\n");
	XSYJ_Data(HANWANG_16_IMSI, HANWANG_16_P33, HANWANG_16_P34, HANWANG_16_P35, HANWANG_16_P36, HANWANG_16_P37, HANWANG_16_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("旱望线 ——  16号桩发送成功。\n");
	sleep(43);
	
	
	printf("正在发送外环巴南段 —— 3号桩：\n");
	XSYJ_Data(BANAN_3_IMSI, BANAN_3_P33, BANAN_3_P34, BANAN_3_P35, BANAN_3_P36, BANAN_3_P37, BANAN_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  3号桩发送成功。\n");
	sleep(44);
	
	
	
	printf("正在发送造纸线 —— 1号桩：\n");
	XSYJ_Data(ZAOZHI_1_IMSI, ZAOZHI_1_P33, ZAOZHI_1_P34, ZAOZHI_1_P35, ZAOZHI_1_P36, ZAOZHI_1_P37, ZAOZHI_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("造纸线 ——  1号桩发送成功。\n");
	sleep(17);
	
	
	
	printf("正在发送外环巴南段 —— 7号桩：\n");
	XSYJ_Data(BANAN_7_IMSI, BANAN_7_P33, BANAN_7_P34, BANAN_7_P35, BANAN_7_P36, BANAN_7_P37, BANAN_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  7号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 9号桩：\n");
	XSYJ_Data(BANAN_9_IMSI, BANAN_9_P33, BANAN_9_P34, BANAN_9_P35, BANAN_9_P36, BANAN_9_P37, BANAN_9_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  9号桩发送成功。\n");
	sleep(41);
	
	printf("正在发送四海线 —— 1号桩：\n");
	XSYJ_Data(SIHAI_1_IMSI, SIHAI_1_P33, SIHAI_1_P34, SIHAI_1_P35, SIHAI_1_P36, SIHAI_1_P37, SIHAI_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("四海线 ——  1号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送外环巴南段 —— 12号桩：\n");
	XSYJ_Data(BANAN_12_IMSI, BANAN_12_P33, BANAN_12_P34, BANAN_12_P35, BANAN_12_P36, BANAN_12_P37, BANAN_12_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  12号桩发送成功。\n");
	sleep(54);
	
	printf("正在发送上长线 —— 4号桩：\n");
	XSYJ_Data(SHANGCHANG_4_IMSI, SHANGCHANG_4_P33, SHANGCHANG_4_P34, SHANGCHANG_4_P35, SHANGCHANG_4_P36, SHANGCHANG_4_P37, SHANGCHANG_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("上长线 ——  4号桩发送成功。\n");
	sleep(2);
	
	printf("正在发送长安线 —— 2号桩：\n");
	XSYJ_Data(CHANGAN_2_IMSI, CHANGAN_2_P33, CHANGAN_2_P34, CHANGAN_2_P35, CHANGAN_2_P36, CHANGAN_2_P37, CHANGAN_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("长安线 ——  2号桩发送成功。\n");
	sleep(21);
	
	printf("正在发送伍桂线 —— 果树园：\n");
	XSYJ_Data(WUGUI_GSY_IMSI, WUGUI_GSY_P33, WUGUI_GSY_P34, WUGUI_GSY_P35, WUGUI_GSY_P36, WUGUI_GSY_P37, WUGUI_GSY_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("伍桂线 ——  果树园发送成功。\n");
	sleep(26);
	
	printf("正在发送人头线 —— 2号桩：\n");
	XSYJ_Data(RENTOU_2_IMSI, RENTOU_2_P33, RENTOU_2_P34, RENTOU_2_P35, RENTOU_2_P36, RENTOU_2_P37, RENTOU_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("人头线 ——  2号桩发送成功。\n");
	sleep(12);
	
	printf("正在发送四茶线 —— 7号桩：\n");
	XSYJ_Data(SICAI_7_IMSI, SICAI_7_P33, SICAI_7_P34, SICAI_7_P35, SICAI_7_P36, SICAI_7_P37, SICAI_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("四茶线 ——  7号桩发送成功。\n");
	sleep(19);
	
	
	
	
	
	printf("正在发送外环巴南段 —— 13号桩：\n");
	XSYJ_Data(BANAN_13_IMSI, BANAN_13_P33, BANAN_13_P34, BANAN_13_P35, BANAN_13_P36, BANAN_13_P37, BANAN_13_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  13号桩发送成功。\n");
	sleep(14);
	
	
	
	printf("正在发送外环巴南段 —— 1号桩：\n");
	XSYJ_Data(BANAN_1_IMSI, BANAN_1_P33, BANAN_1_P34, BANAN_1_P35, BANAN_1_P36, BANAN_1_P37, BANAN_1_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  1号桩发送成功。\n");
	sleep(42);
	
	
	
	printf("正在发送外环巴南段 —— 5号桩：\n");
	XSYJ_Data(BANAN_5_IMSI, BANAN_5_P33, BANAN_5_P34, BANAN_5_P35, BANAN_5_P36, BANAN_5_P37, BANAN_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  5号桩发送成功。\n");
	sleep(11);
	
	printf("正在发送四七线 —— 7号桩：\n");
	XSYJ_Data(SIQI_7_IMSI, SIQI_7_P33, SIQI_7_P34, SIQI_7_P35, SIQI_7_P36, SIQI_7_P37, SIQI_7_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("四七线 ——  7号桩发送成功。\n");
	sleep(26);
	
	printf("正在发送外环巴南段 —— 8号桩：\n");
	XSYJ_Data(BANAN_8_IMSI, BANAN_8_P33, BANAN_8_P34, BANAN_8_P35, BANAN_8_P36, BANAN_8_P37, BANAN_8_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  8号桩发送成功。\n");
	sleep(23);
	
	printf("正在发送长安线 —— 4号桩：\n");
	XSYJ_Data(CHANGAN_4_IMSI, CHANGAN_4_P33, CHANGAN_4_P34, CHANGAN_4_P35, CHANGAN_4_P36, CHANGAN_4_P37, CHANGAN_4_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("长安线 ——  4号桩发送成功。\n");
	sleep(41);
	
	printf("正在发送造纸线 —— 2号桩：\n");
	XSYJ_Data(ZAOZHI_2_IMSI, ZAOZHI_2_P33, ZAOZHI_2_P34, ZAOZHI_2_P35, ZAOZHI_2_P36, ZAOZHI_2_P37, ZAOZHI_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("造纸线 ——  2号桩发送成功。\n");
	sleep(8);
	
	printf("正在发送伍桂线 —— 钢材市场旁：\n");
	XSYJ_Data(WUGUI_GCS_IMSI, WUGUI_GCS_P33, WUGUI_GCS_P34, WUGUI_GCS_P35, WUGUI_GCS_P36, WUGUI_GCS_P37, WUGUI_GCS_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("伍桂线 ——  钢材市场旁发送成功。\n");
	sleep(16);
	
	printf("正在发送人头线 —— 5号桩：\n");
	XSYJ_Data(RENTOU_5_IMSI, RENTOU_5_P33, RENTOU_5_P34, RENTOU_5_P35, RENTOU_5_P36, RENTOU_5_P37, RENTOU_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("人头线 ——  5号桩发送成功。\n");
	sleep(24);
	
	
	
	
	
	
	
	printf("正在发送外环巴南段 —— 6号桩：\n");
	XSYJ_Data(BANAN_6_IMSI, BANAN_6_P33, BANAN_6_P34, BANAN_6_P35, BANAN_6_P36, BANAN_6_P37, BANAN_6_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  6号桩发送成功。\n");
	sleep(42);
	
	printf("正在发送外环巴南段 —— 18号桩：\n");
	XSYJ_Data(BANAN_18_IMSI, BANAN_18_P33, BANAN_18_P34, BANAN_18_P35, BANAN_18_P36, BANAN_18_P37, BANAN_18_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  18号桩发送成功。\n");
	sleep(30);
	
	printf("正在发送伍桂线 —— 报废汽车回收站旁：\n");
	XSYJ_Data(WUGUI_BFQ_IMSI, WUGUI_BFQ_P33, WUGUI_BFQ_P34, WUGUI_BFQ_P35, WUGUI_BFQ_P36, WUGUI_BFQ_P37, WUGUI_BFQ_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("伍桂线 ——  报废汽车回收站旁发送成功。\n");
	sleep(20);

	printf("正在发送外环巴南段 —— 2号桩：\n");
	XSYJ_Data(BANAN_2_IMSI, BANAN_2_P33, BANAN_2_P34, BANAN_2_P35, BANAN_2_P36, BANAN_2_P37, BANAN_2_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  2号桩发送成功。\n");
	sleep(15);
	
	
	printf("正在发送四海线 —— 3号桩：\n");
	XSYJ_Data(SIHAI_3_IMSI, SIHAI_3_P33, SIHAI_3_P34, SIHAI_3_P35, SIHAI_3_P36, SIHAI_3_P37, SIHAI_3_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("四海线 ——  3号桩发送成功。\n");
	sleep(45);
	
	printf("正在发送外环巴南段 —— 10号桩：\n");
	XSYJ_Data(BANAN_10_IMSI, BANAN_10_P33, BANAN_10_P34, BANAN_10_P35, BANAN_10_P36, BANAN_10_P37, BANAN_10_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("外环巴南段 ——  10号桩发送成功。\n");
	sleep(1);

	printf("正在发送茶园迎龙线 —— 5号桩：\n");
	XSYJ_Data(CAIYUAN_5_IMSI, CAIYUAN_5_P33, CAIYUAN_5_P34, CAIYUAN_5_P35, CAIYUAN_5_P36, CAIYUAN_5_P37, CAIYUAN_5_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 5号桩发送成功。\n");
	sleep(21);

	printf("正在发送茶园迎龙线 —— 8号桩：\n");
	XSYJ_Data(CAIYUAN_8_IMSI, CAIYUAN_8_P33, CAIYUAN_8_P34, CAIYUAN_8_P35, CAIYUAN_8_P36, CAIYUAN_8_P37, CAIYUAN_8_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 8号桩发送成功。\n");
	sleep(11);

	printf("正在发送茶园迎龙线 —— 10号桩：\n");
	XSYJ_Data(CAIYUAN_10_IMSI, CAIYUAN_10_P33, CAIYUAN_10_P34, CAIYUAN_10_P35, CAIYUAN_10_P36, CAIYUAN_10_P37, CAIYUAN_10_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 10号桩发送成功。\n");
	sleep(15);

	printf("正在发送茶园迎龙线 —— 426号桩：\n");
	XSYJ_Data(CAIYUAN_426_IMSI, CAIYUAN_426_P33, CAIYUAN_426_P34, CAIYUAN_426_P35, CAIYUAN_426_P36, CAIYUAN_426_P37, CAIYUAN_426_P38);
	send(sock_fd, DataBuf, 50, 0);
	printf("正在发送茶园迎龙线 —— 426号桩发送成功。\n");
	sleep(15);

#endif                                    /* QZDL */
}


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


// 数据整合

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


// 打印头部 2个字节
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

// 打印IMSI码 4个字节
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

// 打印工位号
void PrintWorkNum(void)
{
	DataBuf[10] = 0;
	DataBuf[11] = 1;
}

// 打印CRC校验和
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



// 强制电流型 共4个参数
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
	printf("\t\t断电电位为: %.3f\n", p34);
	
	DataBuf[18] = 0X36;
	PrintParam(p36, 36, 0);
	printf("\t\t自然电位为: %.3f\n", p36);
	
	DataBuf[24] = 0x37;
	PrintParam(p37, 37, 0);
	printf("\t\t电池电压为: %.3f\n", p37);
	
	DataBuf[30] = 0X38;
	PrintParam(p38, 38, 0);
	printf("\t\t通电电位为: %.3f\n", p38);
	
	PrintCRC(0);
}



// 牺牲阳极类型 共6个参数
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
	printf("\t\t开路电位为: %.3f\n", p33);
	
	DataBuf[18] = 0X34;
	PrintParam(p34, 34, 1);
	printf("\t\t断电电位为: %.3f\n", p34);
	
	DataBuf[24] = 0X35;
	PrintParam(p35, 35, 1);
	printf("\t\t保护电流为: %.3f\n", p35);
	
	DataBuf[30] = 0X36;
	PrintParam(p36, 36, 1);
	printf("\t\t自然电位为: %.3f\n", p36);
	
	DataBuf[36] = 0x37;
	PrintParam(p37, 37, 1);
	printf("\t\t电池电压为: %.3f\n", p37);
	
	DataBuf[42] = 0X38;
	PrintParam(p38, 38, 1);
	printf("\t\t通电电位为: %.3f\n", p38);
	
	PrintCRC(1);
}

// 打印参数值共5个字节
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
			                                       // 牺牲阳极
			if (1 == type)
			{
				DataBuf[19] = (unsigned char)temp[3];
				DataBuf[20] = (unsigned char)temp[2];
				DataBuf[21] = (unsigned char)temp[1];
				DataBuf[22] = (unsigned char)temp[0];
				DataBuf[23] = (unsigned char)0;
			}
			
			                                       // 强制电流
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
			                                       // 牺牲阳极
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
			                                       // 牺牲阳极
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
			                                       // 牺牲阳极
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
