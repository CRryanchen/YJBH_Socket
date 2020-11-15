#include "oldToNewProtocol.h"
#include <stdio.h>
#include <string.h>


// ��ˮ����Э�������
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
 * @brief  short�������ݸߵ��ֽڵ���
 * @param  value            ��Ҫת����ֵ
 * @return unsigned short   ת����ɵ�ֵ
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
 * @brief  �¾�Э��ת������
 * @param  szyNewProtocolDesMy ��Э��ṹ�������ַ
 * @param  szyOldProtocolSrcMy ��Э��ṹ�������ַ
 */
void oldCopyToNewProtocol(struct NewProtocol * szyNewProtocolDes, struct OldProtocol * szyOldProtocolSrc)
{
    struct NewProtocol szyNewProtocol = *szyNewProtocolDes;
    struct OldProtocol szyOldProtocol = *szyOldProtocolSrc;

    // ���ֽ���
    szyNewProtocol.m_totalBytes = EndianShort(szyOldProtocol.m_totalbytes.m_shortValue);
    // �豸����
    szyNewProtocol.m_deviceType = SZY;
    // IMSI�� -- �Լ����������������վ������Ψһʶ���
    IMSItoCharBuf("460040313212380", szyNewProtocol.m_deviceCardNum);
    // ϵͳ��λ��
    szyNewProtocol.m_systemNum[0] = szyOldProtocol.m_systemNum[0];
    szyNewProtocol.m_systemNum[1] = szyOldProtocol.m_systemNum[1];
    // ����
    for (int i = 0; i < 4; i++)
    {
        szyNewProtocol.m_params[i].m_paramID = szyOldProtocol.m_params[i].m_paramID;
        szyNewProtocol.m_params[i].m_paramValue = szyOldProtocol.m_params[i].m_paramValue;
        szyNewProtocol.m_params[i].m_paramState = szyOldProtocol.m_params[i].m_paramState;
    }
    // У����
    szyNewProtocol.m_checkNum = szyOldProtocol.m_checkNum;

    *szyNewProtocolDes = szyNewProtocol;
    *szyOldProtocolSrc = szyOldProtocol;
}