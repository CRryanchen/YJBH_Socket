#ifndef OLDTONEWPROTOCOL_H
#define OLDTONEWPROTOCOL_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma pack(1)
/* 宏定义 */





/* 全局变量声明 */

/**
 * @brief 设备类型
 */
enum DeviceType
{
    SZY = 1,
    HJJC,
    YJBH
};

/**
 * @brief 参数结构体数据
 */
struct Param
{
    unsigned char m_paramID;
    float m_paramValue;
    unsigned char m_paramState;
};

/**
 * @brief short类型和两个字符的数组的共用体类型，用于大小端转换和高低字节数据处理
 */
union ShortAndTwoBytes
{
    unsigned char m_bytes[2];
    unsigned short m_shortValue;
};

/**
 * @brief 新的通信协议数据结构体
 */
struct NewProtocol
{
    // 字节总数
    unsigned char m_totalBytes;
    // 设备类型
    unsigned char m_deviceType;
    // 设备卡号
    unsigned char m_deviceCardNum[8];
    // 系统工位号
    unsigned char m_systemNum[2];
    // 参数
    struct Param m_params[4];
    // 校验码
    union ShortAndTwoBytes m_checkNum;
};

/**
 * @brief 旧的通信协议数据结构体
 */
struct OldProtocol
{
    // 字节总数
    union ShortAndTwoBytes m_totalbytes;
    // 手机号
    unsigned char m_phoneNum[5];
    // 系统工位号
    unsigned char m_systemNum[2];
    // 参数
    struct Param m_params[4];
    // 校验码
    union ShortAndTwoBytes m_checkNum;
};

/**
 * @brief float类型和4个字节数组组成的共用体，用于大小端转换
 */
union FloadAndFourBytes
{
    float m_floatValue;
    unsigned char m_bytes[4];
};


/* 函数声明 */
unsigned short EndianShort(unsigned short value);
float EndianFloat(float value);
void IMSItoCharBuf(const char * imsi, unsigned char * startAddr);
void myPrint(unsigned char * startAddr, unsigned char length);
void oldCopyToNewProtocol(struct NewProtocol * szyNewProtocolDes, struct OldProtocol * szyOldProtocolSrc);



#ifdef __cplusplus
}
#endif

#endif /* OLDTONEWPROTOCOL_H */
