/*
  Copyright (c) 2019-2023 BUGSENG srl
  See LICENSE.txt for details.
*/

unsigned return_value(void) {
  typedef enum { Z } S;
  typedef enum {
    I = ((int)-1U/2 == (int)(-1U/2))
        ? (int)-1U : (int)(-1U/2)
  } L;
  struct {
    int f:8;
  } s = { 255 };
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
#ifdef __STDC_VERSION__
  m += (__STDC_VERSION__ % 4)*64;
#else
  m += 192;
#endif
#ifndef __STRICT_ANSI__
  m += 256;
  m += (sizeof("??-") != 4) ? 256 : 0;
#endif
  return m;
}
