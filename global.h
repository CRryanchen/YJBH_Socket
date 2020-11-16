#ifndef __GLOBAL_H
#define __GLOBAL_H

/* 头文件包含 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* 宏定义 */
// 安澜线
#define ANLAN_3_IMSI				"460040313212385"
#define ANLAN_3_P34					(-0.927)
#define ANLAN_3_P36					(-0.556)
#define ANLAN_3_P37					(7.67)
#define ANLAN_3_P38					(-0.998)

#define ANLAN_4_IMSI				"460040313212386"
#define ANLAN_4_P34					(-1.023)
#define ANLAN_4_P36					(-0.535)
#define ANLAN_4_P37					(7.58)
#define ANLAN_4_P38					(-1.098)

#define ANLAN_5_IMSI				"460040313212520"
#define ANLAN_5_P34					(-1.012)
#define ANLAN_5_P36					(-0.553)
#define ANLAN_5_P37					(7.64)
#define ANLAN_5_P38					(-1.087)

#define ANLAN_1_IMSI				"460040313212521"
#define ANLAN_1_P34					(-1.056)
#define ANLAN_1_P36					(-0.549)
#define ANLAN_1_P37					(7.49)
#define ANLAN_1_P38					(-1.112)

// 白梓线
#define BAIZI_16_IMSI				"460043789100177"
#define BAIZI_16_P34				(-1.098)
#define BAIZI_16_P36				(-0.518)
#define BAIZI_16_P37				(7.58)
#define BAIZI_16_P38				(-1.163)

#define BAIZI_3_IMSI				"460043789100178"
#define BAIZI_3_P34					(-1.056)
#define BAIZI_3_P36					(-0.556)
#define BAIZI_3_P37					(7.65)
#define BAIZI_3_P38					(-1.145)

#define BAIZI_4_IMSI				"460043789100179"
#define BAIZI_4_P34					(-1.012)
#define BAIZI_4_P36					(-0.543)
#define BAIZI_4_P37					(7.49)
#define BAIZI_4_P38					(-1.098)

#define BAIZI_8_IMSI				"460043789100180"
#define BAIZI_8_P34					(-1.017)
#define BAIZI_8_P36					(-0.549)
#define BAIZI_8_P37					(7.57)
#define BAIZI_8_P38					(-1.082)

#define BAIZI_1_IMSI				"460043789100181"
#define BAIZI_1_P34					(-0.987)
#define BAIZI_1_P36					(-0.534)
#define BAIZI_1_P37					(7.61)
#define BAIZI_1_P38					(-1.043)

#define BAIZI_15_IMSI				"460043789100182"
#define BAIZI_15_P34				(-1.003)
#define BAIZI_15_P36				(-0.508)
#define BAIZI_15_P37				(7.59)
#define BAIZI_15_P38				(-1.076)

#define BAIZI_7_IMSI				"460043789100235"
#define BAIZI_7_P34					(-1.011)
#define BAIZI_7_P36					(-0.549)
#define BAIZI_7_P37					(7.51)
#define BAIZI_7_P38					(-1.092)

#define BAIZI_12_IMSI				"460043789100236"
#define BAIZI_12_P34				(-1.098)
#define BAIZI_12_P36				(-0.528)
#define BAIZI_12_P37				(7.61)
#define BAIZI_12_P38				(-1.133)

#define BAIZI_14_IMSI				"460043789100241"
#define BAIZI_14_P34				(-1.078)
#define BAIZI_14_P36				(-0.589)
#define BAIZI_14_P37				(7.55)
#define BAIZI_14_P38				(-1.101)

#define BAIZI_5_IMSI				"460043789100243"
#define BAIZI_5_P34					(-1.054)
#define BAIZI_5_P36					(-0.538)
#define BAIZI_5_P37					(7.53)
#define BAIZI_5_P38					(-1.103)

#define BAIZI_10_IMSI				"460043789100244"
#define BAIZI_10_P34				(-1.045)
#define BAIZI_10_P36				(-0.523)
#define BAIZI_10_P37				(7.64)
#define BAIZI_10_P38				(-1.112)

#define BAIZI_9_IMSI				"460043789100245"
#define BAIZI_9_P34					(-1.032)
#define BAIZI_9_P36					(-0.556)
#define BAIZI_9_P37					(7.57)
#define BAIZI_9_P38					(-1.099)

#define BAIZI_17_IMSI				"460043789100246"
#define BAIZI_17_P34				(-1.007)
#define BAIZI_17_P36				(-0.512)
#define BAIZI_17_P37				(7.61)
#define BAIZI_17_P38				(-1.087)

// 旱望线
#define HANWANG_17_IMSI				"460043789100210"
#define HANWANG_17_P33				(-1.532)
#define HANWANG_17_P34				(-1.017)
#define HANWANG_17_P35				(23.364)
#define HANWANG_17_P36				(-0.549)
#define HANWANG_17_P37				(7.57)
#define HANWANG_17_P38				(-1.082)

#define HANWANG_16_IMSI				"460043789100213"
#define HANWANG_16_P33				(-1.527)
#define HANWANG_16_P34				(-0.997)
#define HANWANG_16_P35				(14.38)
#define HANWANG_16_P36				(-0.537)
#define HANWANG_16_P37				(7.51)
#define HANWANG_16_P38				(-1.067)

// 外环巴南线
#define BANAN_7_IMSI				"460043789100155"
#define BANAN_7_P33					(-1.498)
#define BANAN_7_P34					(-0.997)
#define BANAN_7_P35					(9.351)
#define BANAN_7_P36					(-0.549)
#define BANAN_7_P37					(7.45)
#define BANAN_7_P38					(-1.067)

#define BANAN_5_IMSI				"460043789100157"
#define BANAN_5_P33					(-1.510)
#define BANAN_5_P34					(-1.011)
#define BANAN_5_P35					(22.62)
#define BANAN_5_P36					(-0.525)
#define BANAN_5_P37					(7.60)
#define BANAN_5_P38					(-1.083)

#define BANAN_4_IMSI				"460043789100158"
#define BANAN_4_P33					(-1.523)
#define BANAN_4_P34					(-0.986)
#define BANAN_4_P35					(22.694)
#define BANAN_4_P36					(-0.532)
#define BANAN_4_P37					(7.453)
#define BANAN_4_P38					(-1.058)

#define BANAN_2_IMSI				"460043789100159"
#define BANAN_2_P33					(-1.521)
#define BANAN_2_P34					(-1.014)
#define BANAN_2_P35					(6.549)
#define BANAN_2_P36					(-0.525)
#define BANAN_2_P37					(7.61)
#define BANAN_2_P38					(-1.098)

#define BANAN_3_IMSI				"460043789100160"
#define BANAN_3_P33					(-1.499)
#define BANAN_3_P34					(-0.956)
#define BANAN_3_P35					(30.25)
#define BANAN_3_P36					(-0.534)
#define BANAN_3_P37					(7.59)
#define BANAN_3_P38					(-1.087) 

#define BANAN_17_IMSI				"460043789100161"
#define BANAN_17_P33				(-1.521)
#define BANAN_17_P34				(-0.997)
#define BANAN_17_P35				(14.564)
#define BANAN_17_P36				(-0.549)
#define BANAN_17_P37				(7.45)
#define BANAN_17_P38				(-1.067)

#define BANAN_18_IMSI				"460043789100162"
#define BANAN_18_P33				(-1.502)
#define BANAN_18_P34				(-0.957)
#define BANAN_18_P35				(20.69)
#define BANAN_18_P36				(-0.525)
#define BANAN_18_P37				(7.59)
#define BANAN_18_P38				(-1.019)

#define BANAN_13_IMSI				"460043789100163"
#define BANAN_13_P33				(-1.507)
#define BANAN_13_P34				(-1.014)
#define BANAN_13_P35				(13.59)
#define BANAN_13_P36				(-0.523)
#define BANAN_13_P37				(7.61)
#define BANAN_13_P38				(-1.078)
		
#define BANAN_16_IMSI				"460043789100165"
#define BANAN_16_P33				(-1.512)
#define BANAN_16_P34				(-0.927)
#define BANAN_16_P35				(10.336)
#define BANAN_16_P36				(-0.538)
#define BANAN_16_P37				(7.62)
#define BANAN_16_P38				(-0.989)

#define BANAN_1_IMSI				"460043789100166"
#define BANAN_1_P33					(-1.55)
#define BANAN_1_P34					(-1.034)
#define BANAN_1_P35					(24.59)
#define BANAN_1_P36					(-0.526)
#define BANAN_1_P37					(7.65)
#define BANAN_1_P38					(-1.087)

#define BANAN_9_IMSI				"460043789100167"
#define BANAN_9_P33					(-1.498)
#define BANAN_9_P34					(-0.987)
#define BANAN_9_P35					(11.369)
#define BANAN_9_P36					(-0.558)
#define BANAN_9_P37					(7.65)
#define BANAN_9_P38					(-1.059)

#define BANAN_11_IMSI				"460043789100168"
#define BANAN_11_P33				(-1.501)
#define BANAN_11_P34				(-0.967)
#define BANAN_11_P35			 	(25.156)
#define BANAN_11_P36				(-0.546)
#define BANAN_11_P37	 			(7.61)
#define BANAN_11_P38 				(-1.045)

#define BANAN_10_IMSI				"460043789100169"
#define BANAN_10_P33				(-1.512)
#define BANAN_10_P34				(-0.997)
#define BANAN_10_P35			 	(22.389)
#define BANAN_10_P36				(-0.549)
#define BANAN_10_P37	 			(7.55)
#define BANAN_10_P38 				(-1.067)

#define BANAN_8_IMSI				"460043789100170"
#define BANAN_8_P33					(-1.524)
#define BANAN_8_P34					(-1.039)
#define BANAN_8_P35				 	(9.236)
#define BANAN_8_P36					(-0.532)
#define BANAN_8_P37	 				(7.61)
#define BANAN_8_P38 				(-1.098)

#define BANAN_15_IMSI				"460043789100171"
#define BANAN_15_P33				(-1.489)
#define BANAN_15_P34				(-1.032)
#define BANAN_15_P35			 	(12.36)
#define BANAN_15_P36				(-0.518)
#define BANAN_15_P37	 			(7.58)
#define BANAN_15_P38 				(-1.133)

#define BANAN_12_IMSI				"460043789100172"
#define BANAN_12_P33				(-1.520)
#define BANAN_12_P34				(-1.078)
#define BANAN_12_P35			 	(35.36)
#define BANAN_12_P36				(-0.528)
#define BANAN_12_P37	 			(7.65)
#define BANAN_12_P38 				(-1.121)

#define BANAN_6_IMSI				"460043789100173"
#define BANAN_6_P33					(-1.532)
#define BANAN_6_P34					(-0.927)
#define BANAN_6_P35				 	(16.369)
#define BANAN_6_P36					(-0.538)
#define BANAN_6_P37	 				(7.62)
#define BANAN_6_P38 				(-0.989)

#define BANAN_14_IMSI				"460043789100174"
#define BANAN_14_P33				(-1.512)
#define BANAN_14_P34				(-0.997)
#define BANAN_14_P35			 	(33.36)
#define BANAN_14_P36				(-0.549)
#define BANAN_14_P37	 			(7.45)
#define BANAN_14_P38 				(-1.067)

// 上长线
#define SHANGCHANG_4_IMSI			"460043789100201"
#define SHANGCHANG_4_P33			(-1.520)
#define SHANGCHANG_4_P34			(-1.024)
#define SHANGCHANG_4_P35		 	(22.36)
#define SHANGCHANG_4_P36			(-0.525)
#define SHANGCHANG_4_P37	 		(7.58)
#define SHANGCHANG_4_P38 			(-1.099)

#define SHANGCHANG_5_IMSI			"460043789100212"
#define SHANGCHANG_5_P33			(-1.510)
#define SHANGCHANG_5_P34			(-1.098)
#define SHANGCHANG_5_P35		 	(29.36)
#define SHANGCHANG_5_P36			(-0.528)
#define SHANGCHANG_5_P37	 		(7.61)
#define SHANGCHANG_5_P38 			(-1.133)

// 长安线
#define CHANGAN_4_IMSI				"460043789100149"
#define CHANGAN_4_P33				(-1.520)
#define CHANGAN_4_P34				(-1.014)
#define CHANGAN_4_P35			 	(4.369)
#define CHANGAN_4_P36				(-0.532)
#define CHANGAN_4_P37	 			(7.66)
#define CHANGAN_4_P38 				(-1.089)

#define CHANGAN_1_IMSI				"460043789100153"
#define CHANGAN_1_P33				(-1.532)
#define CHANGAN_1_P34				(-0.927)
#define CHANGAN_1_P35			 	(25.36)
#define CHANGAN_1_P36				(-0.538)
#define CHANGAN_1_P37	 			(7.62)
#define CHANGAN_1_P38 				(-0.989)

#define CHANGAN_2_IMSI				"460043789100154"
#define CHANGAN_2_P33				(-1.512)
#define CHANGAN_2_P34				(-0.997)
#define CHANGAN_2_P35			 	(12.36)
#define CHANGAN_2_P36				(-0.549)
#define CHANGAN_2_P37	 			(7.55)
#define CHANGAN_2_P38 				(-1.067)

// 造纸线
#define ZAOZHI_1_IMSI				"460040313212388"
#define ZAOZHI_1_P33				(-1.530)
#define ZAOZHI_1_P34				(-1.044)
#define ZAOZHI_1_P35			 	(23.36)
#define ZAOZHI_1_P36				(-0.529)
#define ZAOZHI_1_P37	 			(7.51)
#define ZAOZHI_1_P38 				(-1.099)

#define ZAOZHI_2_IMSI				"460040313212533"
#define ZAOZHI_2_P33				(-1.523)
#define ZAOZHI_2_P34				(-1.023)
#define ZAOZHI_2_P35				(16.365)
#define ZAOZHI_2_P36				(-0.532)
#define ZAOZHI_2_P37	 			(7.56)
#define ZAOZHI_2_P38 				(-1.078)

#define ZAOZHI_3_IMSI				"460040337701477"
#define ZAOZHI_3_P33				(-1.490)
#define ZAOZHI_3_P34				(-0.957)
#define ZAOZHI_3_P35			 	(15.366)
#define ZAOZHI_3_P36				(-0.524)
#define ZAOZHI_3_P37	 			(7.46)
#define ZAOZHI_3_P38 				(-1.043)

// 四七线
#define SIQI_2_IMSI					"460043789100203"
#define SIQI_2_P33					(-1.512)
#define SIQI_2_P34					(-0.986)
#define SIQI_2_P35				 	(36.33)
#define SIQI_2_P36					(-0.549)
#define SIQI_2_P37	 				(7.51)
#define SIQI_2_P38 					(-1.012)

#define SIQI_7_IMSI					"460043789100204"
#define SIQI_7_P33					(-1.520)
#define SIQI_7_P34					(-1.064)
#define SIQI_7_P35				 	(19.87)
#define SIQI_7_P36					(-0.532)
#define SIQI_7_P37	 				(7.61)
#define SIQI_7_P38 					(-1.098)

// 伍桂线 
#define WUGUI_GSY_IMSI				"460043789100207"
#define WUGUI_GSY_P33				(-1.520)
#define WUGUI_GSY_P34				(-1.066)
#define WUGUI_GSY_P35				(33.65)
#define WUGUI_GSY_P36				(-0.538)
#define WUGUI_GSY_P37	 			(7.57)
#define WUGUI_GSY_P38 				(-1.103)

#define WUGUI_TJT_IMSI				"460043789100208"
#define WUGUI_TJT_P33				(-1.58)
#define WUGUI_TJT_P34				(-0.987)
#define WUGUI_TJT_P35			 	(26.3)
#define WUGUI_TJT_P36				(-0.556)
#define WUGUI_TJT_P37	 			(7.493)
#define WUGUI_TJT_P38 				(-1.032)

#define WUGUI_GCS_IMSI				"460043789100211"
#define WUGUI_GCS_P33				(-1.49)
#define WUGUI_GCS_P34				(-1.067)
#define WUGUI_GCS_P35			 	(27.36)
#define WUGUI_GCS_P36				(-0.573)
#define WUGUI_GCS_P37	 			(7.476)
#define WUGUI_GCS_P38 				(-1.102)

#define WUGUI_BFQ_IMSI				"460043789100214"
#define WUGUI_BFQ_P33				(-1.515)
#define WUGUI_BFQ_P34				(-1.034)
#define WUGUI_BFQ_P35				(8.33)
#define WUGUI_BFQ_P36				(-0.526)
#define WUGUI_BFQ_P37	 			(7.65)
#define WUGUI_BFQ_P38 				(-1.097)

// 人头线 
#define RENTOU_2_IMSI				"460043789100150"
#define RENTOU_2_P33				(-1.498)
#define RENTOU_2_P34				(-1.023)
#define RENTOU_2_P35			 	(30.155)
#define RENTOU_2_P36				(-0.567)
#define RENTOU_2_P37	 			(7.59)
#define RENTOU_2_P38 				(-1.098)

#define RENTOU_5_IMSI				"460043789100151"
#define RENTOU_5_P33				(-1.509)
#define RENTOU_5_P34				(-0.947)
#define RENTOU_5_P35				(11.336)
#define RENTOU_5_P36				(-0.549)
#define RENTOU_5_P37	 			(7.62)
#define RENTOU_5_P38 				(-0.997)

#define RENTOU_7_IMSI				"460043789100152"
#define RENTOU_7_P33				(-1.510)
#define RENTOU_7_P34				(-1.054)
#define RENTOU_7_P35				(16.317)
#define RENTOU_7_P36				(-0.538)
#define RENTOU_7_P37	 			(7.53)
#define RENTOU_7_P38 				(-1.103)

// 四海线
#define SIHAI_3_IMSI				"460043789100202"
#define SIHAI_3_P33					(-1.532)
#define SIHAI_3_P34					(-0.92)
#define SIHAI_3_P35					(20.366)
#define SIHAI_3_P36					(-0.523)
#define SIHAI_3_P37	 				(7.51)
#define SIHAI_3_P38 				(-0.987)

#define SIHAI_1_IMSI				"460043789100206"
#define SIHAI_1_P33					(-1.489)
#define SIHAI_1_P34					(-1.03)
#define SIHAI_1_P35				 	(5.112)
#define SIHAI_1_P36					(-0.528)
#define SIHAI_1_P37	 				(7.58)
#define SIHAI_1_P38 				(-1.13)

// 四茶线
#define SICAI_7_IMSI				"460043789100200"
#define SICAI_7_P33					(-1.493)
#define SICAI_7_P34					(-0.95)
#define SICAI_7_P35				 	(6.88)
#define SICAI_7_P36					(-0.521)
#define SICAI_7_P37	 				(7.45)
#define SICAI_7_P38 				(-1.057) 


// 茶园--迎龙
#define CAIYUAN_5_IMSI				"460043789100192"
#define CAIYUAN_5_P33				(-1.482)
#define CAIYUAN_5_P34				(-0.87)
#define CAIYUAN_5_P35				(17.284)
#define CAIYUAN_5_P36				(-0.483)
#define CAIYUAN_5_P37	 			(7.49)
#define CAIYUAN_5_P38 				(-1.087)

#define CAIYUAN_8_IMSI				"460043789100195"
#define CAIYUAN_8_P33				(-1.512)
#define CAIYUAN_8_P34				(-0.92)
#define CAIYUAN_8_P35				(23.184)
#define CAIYUAN_8_P36				(-0.533)
#define CAIYUAN_8_P37	 			(7.52)
#define CAIYUAN_8_P38 				(-0.957)

#define CAIYUAN_10_IMSI				"460043789100191"
#define CAIYUAN_10_P33				(-1.493)
#define CAIYUAN_10_P34				(-0.97)
#define CAIYUAN_10_P35				(18.294)
#define CAIYUAN_10_P36				(-0.547)
#define CAIYUAN_10_P37	 			(7.55)
#define CAIYUAN_10_P38 				(-1.023)

#define CAIYUAN_426_IMSI			"460043789100188"
#define CAIYUAN_426_P33				(-1.601)
#define CAIYUAN_426_P34				(-0.86)
#define CAIYUAN_426_P35				(25.334)
#define CAIYUAN_426_P36				(-0.477)
#define CAIYUAN_426_P37	 			(7.63)
#define CAIYUAN_426_P38 			(-0.899)

// 演示线
// 106.50445,29.281888
#define YANSHI_1_IMSI				"460050313212395"
#define YANSHI_1_P33				(-1.482)
#define YANSHI_1_P34				(-0.87)
#define YANSHI_1_P35				(17.284)
#define YANSHI_1_P36				(-0.483)
#define YANSHI_1_P37	 			(7.49)
#define YANSHI_1_P38 				(-1.087)

// 106.509988,29.285417
#define YANSHI_2_IMSI				"460050313212396"
#define YANSHI_2_P33				(-1.482)
#define YANSHI_2_P34				(-0.87)
#define YANSHI_2_P35				(17.284)
#define YANSHI_2_P36				(-0.483)
#define YANSHI_2_P37	 			(7.49)
#define YANSHI_2_P38 				(-1.087)

// 106.514655,29.287752
#define YANSHI_3_IMSI				"460050313212397"
#define YANSHI_3_P33				(-1.482)
#define YANSHI_3_P34				(-0.87)
#define YANSHI_3_P35				(17.284)
#define YANSHI_3_P36				(-0.483)
#define YANSHI_3_P37	 			(7.49)
#define YANSHI_3_P38 				(-1.087)


struct YjbhProtocol
{
    char m_char[16];

};

#endif /* __GLOBAL_H */
