#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char * p = "460040313212380";
    char buf[8];
    long long temp = 0;
    unsigned char resultBuf[8];
    temp = atoll(p);
    

    for (int i = 0; i < 8; i++)
    {

    }

    printf("%lld\n", temp);
    for (int i = 0; i < 8; i++)
    {
        printf("%lld\n", (unsigned long long)pow(100, i));
        resultBuf[7 - i] = (temp / (unsigned long long)pow(100, i)) % 100;
    }

    // resultBuf[7] = temp % 100;
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

    // printf("%d\n", temp % 256);
    // printf("&temp = %02d\t", *((unsigned char *)(&temp)));
    for (int i = 0; i < 8; i++)
    {
        printf("Buf[%d] = %02d\t", i, resultBuf[i]);
    }

    return 0;
}