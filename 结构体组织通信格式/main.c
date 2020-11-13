#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#pragma pack(1)
#define OLD_METHOD
// ˮ��������

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
    struct _params params[2];
}YJBH;


struct OLD_SZY
{
    // �ֽ�����
    unsigned char m_totalByes[2];
    // �ֻ���
    unsigned char m_phoneNum[5];
    // ϵͳ��λ��
    unsigned char systemNum[2];
    // ����
    struct _params m_params[4];
};

union _floatConv
{
    float f;
    unsigned char c[4];
};


float EndianFloat(float value)
{
    union _floatConv f1, f2;
    f1.f = value;

    // printf("---------------------------------\n");
    // printf("%02x\n",  f1.c[0]);
    // printf("%02x\n",  f1.c[1]);
    // printf("%02x\n",  f1.c[2]);
    // printf("%02x\n",  f1.c[3]);
    // printf("---------------------------------\n");

    f2.c[0] = f1.c[3];
    f2.c[1] = f1.c[2];
    f2.c[2] = f1.c[1];
    f2.c[3] = f1.c[0];

    return f2.f;
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
// #ifdef OLD_METHOD
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

    for (int i = 0; i < 8; i++)
    {
        resultBuf[7 - i] = (temp / (unsigned long long)pow(100, i)) % 100;
    }
    // resultBuf[7] = (temp / 1) % 100;
    // resultBuf[6] = (temp / 100) % 100;
    // resultBuf[5] = (temp / 10000) % 100;
    // resultBuf[4] = (temp / 1000000) % 100;
    // resultBuf[3] = (temp / 100000000) % 100;
    // resultBuf[2] = (temp / 10000000000) % 100;
    // resultBuf[1] = (temp / 1000000000000) % 100;
    // resultBuf[0] = (temp / 100000000000000) % 100;

    // resultBuf[7] = (temp % 10000) % 100;
    // resultBuf[6] = (temp % 10000) / 100;
    // resultBuf[5] = ((temp % 100000000) / 10000) % 100;
    // resultBuf[4] = ((temp % 100000000) / 10000) / 100;
    // resultBuf[3] = ((temp % 1000000000000) / 100000000) % 100;
    // resultBuf[2] = ((temp % 1000000000000) / 100000000) / 100;
    // resultBuf[1] = ((temp % 10000000000000000) / 1000000000000) % 100;
    // resultBuf[0] = ((temp % 10000000000000000) / 1000000000000) / 100;

#endif

    memcpy(startAddr, resultBuf, 8);
}



int main()
{
    // �������
    YJBH.totalBytes = 1;
    YJBH.deviceType = 2;
    char test[8];
    IMSItoCharBUf("460040313212380", YJBH.deviceCardNum);
    // ϵͳ��λ��
    YJBH.systemNum[0] = 0;
    YJBH.systemNum[1] = 1;
    // ����1
    YJBH.params[0].paramID = 01;
    YJBH.params[0].paramValue = EndianFloat(1.0);
    YJBH.params[0].paramState = 0;
    // ����2
    YJBH.params[1].paramID = 2;
    YJBH.params[1].paramValue = EndianFloat(2.0);
    YJBH.params[1].paramState = 1;

    printf("struct _params = %d\n", sizeof(struct _params));

    // printf("YJBH addr = %x\n", &YJBH);
    // // ϵͳ��λ�ŵ�ַ
    // printf("systemID addr = %x\n", YJBH.systemNum);
    // // ������ַ
    // printf("params addr = %x\n", YJBH.params);
    // printf("params[0].paramID addr = %x\n", &(YJBH.params[0].paramID));
    // printf("params[0].paramValue addr = %x\n", &(YJBH.params[0].paramValue));
    // printf("params[0].paramState addr = %x\n", &(YJBH.params[0].paramState));
    // printf("params[1].paramID addr = %x\n", &(YJBH.params[1].paramID));
    // printf("params[1].paramValue addr = %x\n", &(YJBH.params[1].paramValue));
    // printf("params[1].paramState addr = %x\n", &(YJBH.params[1].paramState));
    print((unsigned char *)&YJBH, sizeof(YJBH));

}