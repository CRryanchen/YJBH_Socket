#include "oldToNewProtocol.h"
#include <stdio.h>
#include <string.h>


// 旧水质依协议的数据
unsigned char oldProtocolDataBuf[] = {0x00, 0x23,
                                      0x00, 0x00, 0x00, 0x00, 0x00,
                                      0x00, 0x61,
                                      0x07, 0x3D, 0x9A, 0xF6, 0x39, 0x00,
                                      0x09, 0x3E, 0x00, 0x00, 0x00, 0x00,
                                      0x0A, 0x41, 0x90, 0x00, 0x00, 0x00,
                                      0x11, 0x40, 0xF5, 0x33, 0x74, 0x00,
                                      0x14, 0x0C};

// int main(int argc, char * argv[])
// {
//     struct NewProtocol szyNewProtocol;
//     struct OldProtocol szyOldProtocol;

//     szyOldProtocol = *(struct OldProtocol *)oldProtocolDataBuf;
//     oldCopyToNewProtocol(&szyNewProtocol, &szyOldProtocol);

//     myPrint((unsigned char *)&szyNewProtocol, sizeof(szyNewProtocol));
//     return 0;
// }

/**
 * @brief  short类型数据高低字节调换
 * @param  value            需要转换的值
 * @return unsigned short   转换完成的值
 */
unsigned short EndianShort(unsigned short value)
{
    union ShortAndTwoBytes src, des;
    src.m_shortValue = value;

    des.m_bytes[0] = src.m_bytes[1];
    des.m_bytes[1] = src.m_bytes[0];

    return des.m_shortValue;
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
 * @brief  新旧协议转换函数
 * @param  szyNewProtocolDesMy 新协议结构体变量地址
 * @param  szyOldProtocolSrcMy 旧协议结构体变量地址
 */
void oldCopyToNewProtocol(struct NewProtocol * szyNewProtocolDes, struct OldProtocol * szyOldProtocolSrc)
{
    struct NewProtocol szyNewProtocol = *szyNewProtocolDes;
    struct OldProtocol szyOldProtocol = *szyOldProtocolSrc;

    // 总字节数
    szyNewProtocol.m_totalBytes = EndianShort(szyOldProtocol.m_totalbytes.m_shortValue);
    // 设备类型
    szyNewProtocol.m_deviceType = SZY;
    // IMSI码 -- 自己创建的虚拟的在网站上用于唯一识别的
    IMSItoCharBuf("460040313212380", szyNewProtocol.m_deviceCardNum);
    // 系统工位号
    szyNewProtocol.m_systemNum[0] = szyOldProtocol.m_systemNum[0];
    szyNewProtocol.m_systemNum[1] = szyOldProtocol.m_systemNum[1];
    // 参数
    for (int i = 0; i < 4; i++)
    {
        szyNewProtocol.m_params[i].m_paramID = szyOldProtocol.m_params[i].m_paramID;
        szyNewProtocol.m_params[i].m_paramValue = szyOldProtocol.m_params[i].m_paramValue;
        szyNewProtocol.m_params[i].m_paramState = szyOldProtocol.m_params[i].m_paramState;
    }
    // 校验码
    szyNewProtocol.m_checkNum = szyOldProtocol.m_checkNum;

    *szyNewProtocolDes = szyNewProtocol;
    *szyOldProtocolSrc = szyOldProtocol;
}