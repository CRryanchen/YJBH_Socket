#ifndef OLDTONEWPROTOCOL_H
#define OLDTONEWPROTOCOL_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma pack(1)
/* �궨�� */





/* ȫ�ֱ������� */

/**
 * @brief �豸����
 */
enum DeviceType
{
    SZY = 1,
    HJJC,
    YJBH
};

/**
 * @brief �����ṹ������
 */
struct Param
{
    unsigned char m_paramID;
    float m_paramValue;
    unsigned char m_paramState;
};

/**
 * @brief short���ͺ������ַ�������Ĺ��������ͣ����ڴ�С��ת���͸ߵ��ֽ����ݴ���
 */
union ShortAndTwoBytes
{
    unsigned char m_bytes[2];
    unsigned short m_shortValue;
};

/**
 * @brief �µ�ͨ��Э�����ݽṹ��
 */
struct NewProtocol
{
    // �ֽ�����
    unsigned char m_totalBytes;
    // �豸����
    unsigned char m_deviceType;
    // �豸����
    unsigned char m_deviceCardNum[8];
    // ϵͳ��λ��
    unsigned char m_systemNum[2];
    // ����
    struct Param m_params[4];
    // У����
    union ShortAndTwoBytes m_checkNum;
};

/**
 * @brief �ɵ�ͨ��Э�����ݽṹ��
 */
struct OldProtocol
{
    // �ֽ�����
    union ShortAndTwoBytes m_totalbytes;
    // �ֻ���
    unsigned char m_phoneNum[5];
    // ϵͳ��λ��
    unsigned char m_systemNum[2];
    // ����
    struct Param m_params[4];
    // У����
    union ShortAndTwoBytes m_checkNum;
};

/**
 * @brief float���ͺ�4���ֽ�������ɵĹ����壬���ڴ�С��ת��
 */
union FloadAndFourBytes
{
    float m_floatValue;
    unsigned char m_bytes[4];
};


/* �������� */
unsigned short EndianShort(unsigned short value);
float EndianFloat(float value);
void IMSItoCharBuf(const char * imsi, unsigned char * startAddr);
void myPrint(unsigned char * startAddr, unsigned char length);
void oldCopyToNewProtocol(struct NewProtocol * szyNewProtocolDes, struct OldProtocol * szyOldProtocolSrc);



#ifdef __cplusplus
}
#endif

#endif /* OLDTONEWPROTOCOL_H */
