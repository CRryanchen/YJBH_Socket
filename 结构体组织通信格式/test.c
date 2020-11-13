#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#pragma pack(1)
#define OLD_METHOD

// ˮ��������
unsigned char g_buf[] = {0x00, 0x23,
                        0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x61,
                        0x07, 0x3D, 0x9A, 0xF6, 0x39, 0x00,
                        0x09, 0x3E, 0x00, 0x00, 0x00, 0x00,
                        0x0A, 0x41, 0x90, 0x00, 0x00, 0x00,
                        0x11, 0x40, 0xF5, 0x33, 0x74, 0x00,
                        0x14, 0x0C};

/**
 * @brief �豸����
 */
enum _deviceTypes
{
    _SZY = 1,
    _HJJC,
    _YJBH
};



/**
 * @brief �����ṹ������
 */
struct _params
{
    unsigned char paramID;
    float paramValue;
    unsigned char paramState;
}PARAM;


union TOTAL_BYTES
{
    unsigned char m_ucBytes[2];
    unsigned short m_shortValue;
};


/**
 * @brief ����ͨ�Ÿ�ʽ�ṹ��
 */
struct yjbh
{
    // �ֽ�����
    unsigned char totalBytes;
    // �豸����
    unsigned char deviceType;
    // �豸����
    unsigned char deviceCardNum[8];
    // ϵͳ��λ��
    unsigned char systemNum[2];
    // ����
    struct _params params[4];
    // У����
    union TOTAL_BYTES m_checkNum;
}YJBH;




struct OLD_SZY
{
    // �ֽ�����
    union TOTAL_BYTES m_totalbytes;
    // �ֻ���
    unsigned char m_phoneNum[5];
    // ϵͳ��λ��
    unsigned char systemNum[2];
    // ����
    struct _params m_params[4];
    // У����
    union TOTAL_BYTES m_checkNum;
};

// ��������
void print(unsigned char * startAddr, unsigned char length);
void IMSItoCharBUf(const char * imsi, unsigned char * startAddr);


union _floatConv
{
    float f;
    unsigned char c[4];
};

unsigned short EndianShort(unsigned short value)
{
    union TOTAL_BYTES f1, f2;
    f1.m_shortValue = value;

    f2.m_ucBytes[0] = f1.m_ucBytes[1];
    f2.m_ucBytes[1] = f1.m_ucBytes[0];

    return f2.m_shortValue;
}


float EndianFloat(float value)
{
    union _floatConv f1, f2;
    f1.f = value;

    f2.c[0] = f1.c[3];
    f2.c[1] = f1.c[2];
    f2.c[2] = f1.c[1];
    f2.c[3] = f1.c[0];

    return f2.f;
}


int main(void)
{
    struct OLD_SZY temp1;
    struct yjbh temp2;

    temp1 = *(struct OLD_SZY *)g_buf;

    printf("temp1.m_totalByes[0] = %x, temp1.m_totalByes[1] = %x\n", temp1.m_totalbytes.m_ucBytes[0], temp1.m_totalbytes.m_ucBytes[1]);
    printf("temp1.m_totalbytes.m_shortValue = %x\n", EndianShort(temp1.m_totalbytes.m_shortValue));
    // ���ֽ���
    temp2.totalBytes = EndianShort(temp1.m_totalbytes.m_shortValue);
    // �豸����
    temp2.deviceType = _SZY;
    // IMSI��
    IMSItoCharBUf("460040313212380", temp2.deviceCardNum);
    // ϵͳ��λ��
    temp2.systemNum[0] = temp1.systemNum[0];
    temp2.systemNum[1] = temp1.systemNum[1];
    // ����1
    temp2.params[0].paramID = temp1.m_params[0].paramID;
    temp2.params[0].paramValue = temp1.m_params[0].paramValue;
    temp2.params[0].paramState = temp1.m_params[0].paramState;
    // ����2
    temp2.params[1].paramID = temp1.m_params[1].paramID;
    temp2.params[1].paramValue = temp1.m_params[1].paramValue;
    temp2.params[1].paramState = temp1.m_params[1].paramState;
    // ����3
    temp2.params[2].paramID = temp1.m_params[2].paramID;
    temp2.params[2].paramValue = temp1.m_params[2].paramValue;
    temp2.params[2].paramState = temp1.m_params[2].paramState;
    // ����4
    temp2.params[3].paramID = temp1.m_params[3].paramID;
    temp2.params[3].paramValue = temp1.m_params[3].paramValue;
    temp2.params[3].paramState = temp1.m_params[3].paramState;
    // У����
    temp2.m_checkNum = temp1.m_checkNum;

    print((unsigned char *)&temp2, sizeof(temp2));

    // printf("sizeof(OLD_SZY) = %d\n", sizeof(struct OLD_SZY));
    // printf("sizeof(g_buf) = %d\n", sizeof(g_buf));

    // temp1 = *(struct OLD_SZY *)g_buf;
    // printf("temp1.m_totalByes[0] = %x, temp1.m_totalByes[1] = %x\n", temp1.m_totalByes[0], temp1.m_totalByes[1]);
    // printf("m_phoneNum[0] = %x, m_phoneNum[1] = %x, m_phoneNum[2] = %x, m_phoneNum[3] = %x, m_phoneNum[4] = %x, temp1.m_phoneNum[5] = %x\n", temp1.m_phoneNum[0], temp1.m_phoneNum[1], temp1.m_phoneNum[2], temp1.m_phoneNum[3], temp1.m_phoneNum[4]);
    // printf("temp1.systemNum[0] = %x, temp1.systemNum[1] = %x\n", temp1.systemNum[0], temp1.systemNum[1]);
    // printf("��һ�������ı����%x,ֵ��%f,״̬��%x\n", temp1.m_params[0].paramID, EndianFloat(temp1.m_params[0].paramValue), temp1.m_params[0].paramState);
    // printf("�ڶ��������ı����%x,ֵ��%f,״̬��%x\n", temp1.m_params[1].paramID, EndianFloat(temp1.m_params[1].paramValue), temp1.m_params[1].paramState);
    // printf("�����������ı����%x,ֵ��%f,״̬��%x\n", temp1.m_params[2].paramID, EndianFloat(temp1.m_params[2].paramValue), temp1.m_params[2].paramState);
    // printf("���ĸ������ı����%x,ֵ��%f,״̬��%x\n", temp1.m_params[3].paramID, EndianFloat(temp1.m_params[3].paramValue), temp1.m_params[3].paramState);

    return 0;
}

void print(unsigned char * startAddr, unsigned char length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%02x  ", *(startAddr + i));
    }
    putchar('\n');
}


// ��IMSI�ַ���ת��Ϊunsigned char����
void IMSItoCharBUf(const char * imsi, unsigned char * startAddr)
{
    unsigned char resultBuf[8];
    unsigned long long temp;

#if defined OLD_METHOD
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
#else
    temp = atoll(imsi);
    printf("%lld\n", temp);
    for (int i = 0; i < 8; i++)
    {
        resultBuf[7 - i] = (temp / (unsigned long long)pow(100, i)) % 100;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("Buf[%d] = %02d\t", i, resultBuf[i]);
    }

#endif
    memcpy(startAddr, resultBuf, 8);
}