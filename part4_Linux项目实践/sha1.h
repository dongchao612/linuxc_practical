#ifndef SHA1_H
#define SHA1_H

/*
 *	本文件中的函数用于对一段文本使用sha1算法计算其HASH值
 *  本文件为自由的开放源代码,可以任意使用,实现细节不必理会,只需使用即可
 */

/*
SHA-1 in C   By Steve Reid <steve@edmweb.com>   100% Public Domain

Test Vectors (from FIPS PUB 180-1)
"abc"
  A9993E36 4706816A BA3E2571 7850C26C 9CD0D89D
"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
  84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1
A million repetitions of "a"
  34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F
*/

#include <sys/types.h>

#define SHA1HANDSOFF

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned long state[ 5 ];
    unsigned long count[ 2 ];
    unsigned char buffer[ 64 ];
} SHA1_CTX;

void SHA1Transform( unsigned long state[ 5 ], unsigned char buffer[ 64 ] );
void SHA1Init( SHA1_CTX* context );
void SHA1Update( SHA1_CTX* context, unsigned char* data, unsigned int len );
void SHA1Final( unsigned char digest[ 20 ], SHA1_CTX* context );

#ifdef __cplusplus
}
#endif

#endif