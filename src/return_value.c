/*
  Copyright (c) 2019-2023 BUGSENG srl
  See LICENSE.txt for details.
*/

#include <stddef.h>

unsigned return_value(void) {
  typedef enum { Z } S;
  typedef enum {
    I = ((int)-1U/2 == (int)(-1U/2))
        ? (int)-1U : (int)(-1U/2)
  } L;
  struct {
    int f:8;
  } s = { 255 };
  struct {
    char foo : 4;
    short : 0;
    char bar;
  } t;
  union {
    int i;
    unsigned char c[4];
  } u = { 0x12345678 };
  unsigned m = 0;
  m += (((char)-1) < 0) ? 1 : 0;
  m += (s.f < 0) ? 2 : 0;
  m += (sizeof(S) < sizeof(L)) ? 4 : 0;
#ifdef __OPTIMIZE__
  m += 8;
#endif
  m += (sizeof(void *) == 8)
       ? 16 : 0;
#if !defined(__STDC_HOSTED__) \
    || __STDC_HOSTED__ == 0
  m += 32;
#endif
#if (__CET__ & 2) == 2
  m += 64;
#endif
  m += (sizeof(wchar_t) - 2)*64;
#ifdef __pic__
  m += (__pic__%2)*256;
#endif
#if (__CET__ & 1) == 1
  m += 512;
#endif
#ifndef __STDC_IEC_559__
  m += 1024;
#endif
#ifdef __SUPPORT_SNAN__
  m += 2048;
#endif
#ifdef __SSP_ALL__
  m += 4096;
#endif
#ifdef __3dNOW_A__
  m += 8192;
#endif
#ifdef _OPENACC
  m += 16384;
#endif
#ifdef _OPENMP
  m += 32768;
#endif
#ifdef __LIBGCC_HAS_SF_MODE__
  m += 65536;
#endif
  m += (sizeof(t) - 3)*131072;
  m += (u.c[0] == 0x12) ? 262144 : 0;
#ifdef __STDC_VERSION__
  m += (__STDC_VERSION__ % 4)*524288;
#else
  m += 1572864;
#endif
#ifndef __STRICT_ANSI__
  m += 2097152;
  m += (sizeof("??-") != 4) ? 2097152 : 0;
#endif
  {
    unsigned x = (16 - sizeof(long double))/4;
    unsigned z = (__BIGGEST_ALIGNMENT__ - 16)/16;
    unsigned y = (z == 3) ? 2 : z;
    z = x + 3*y;
    m += 6291456*z;
  }
  return m;
}
