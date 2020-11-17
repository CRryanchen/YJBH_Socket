#ifndef __MAIN_H
#define __MAIN_H

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
 * @brief �µ�ͨ��Э�����ݽṹ�� -- ǿ�Ƶ���������������
 */
struct NewProtocolQzdl
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
 * @brief �µ�ͨ��Э�����ݽṹ�� -- ����������������������
 */
struct NewProtocolXsyj
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
    struct Param m_params[6];
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

#endif /* __MAIN_H */
