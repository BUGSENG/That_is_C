/*
  Copyright (c) 2019-2023 BUGSENG srl
  See LICENSE.txt for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define MAX_VALUE 56623103
void print_cmd(const char *arg) {
  char *endptr;
  long value = strtol(arg, &endptr, 10);
  if (*endptr != '\0') {
    printf("invalid argument\n");
    return;
  }
  if (value < 0 || value > MAX_VALUE) {
    printf("argument not in range 0..%d\n", MAX_VALUE);
    return;
  }
  if (value & 1) {
    printf("-fsigned-char ");
  }
  else {
    printf("-funsigned-char ");
  }
  if (value & 2) {
    printf("-fsigned-bitfields ");
  }
  else {
    printf("-funsigned-bitfields ");
  }
  if (value & 4) {
    printf("-fshort-enums ");
  }
  if (value & 8) {
    printf("-O2 ");
  }
  if (value & 16) {
    printf("-m64 ");
  }
  else {
    printf("-m32 ");
  }
  if (value & 32) {
    printf("-ffreestanding ");
  }
  else {
    printf("-fhosted ");
  }
  if (value & 64) {
    if (value & 512) {
      printf("-fcf-protection=full ");
    }
    else {
      printf("-fcf-protection=return ");
    }
  }
  else {
    if (value & 512) {
      printf("-fcf-protection=branch ");
    }
    else {
      printf("-fcf-protection=none ");
    }
  }
  if (value & 128) {
  }
  else {
    printf("-fshort-wchar ");
  }
  if (value & 256) {
    printf("-fpie ");
  }
  if (value & 1024) {
    printf("-ffast-math ");
  }
  if (value & 2048) {
    printf("-fsignaling-nans ");
  }
  if (value & 4096) {
    printf("-fstack-protector-all ");
  }
  if (value & 8192) {
    printf("-m3dnowa ");
  }
  if (value & 16384) {
    printf("-fopenacc ");
  }
  if (value & 32768) {
    printf("-fopenmp ");
  }
  if (value & 65536) {
    printf("-fbuilding-libgcc ");
  }
  if (value & 131072) {
    printf("-mms-bitfields ");
  }
  if (value & 262144) {
    printf("-fsso-struct=big-endian ");
  }
  const char *a[108]
    = {
    "-std=c11",
    "-std=c99",
    "-std=c17",
    "-std=c90",
    "-std=gnu11",
    "-std=gnu99",
    "-std=gnu17",
    "-std=gnu90",
    "-std=gnu11 -trigraphs",
    "-std=gnu99 -trigraphs",
    "-std=gnu17 -trigraphs",
    "-std=gnu90 -trigraphs",
    "-m96bit-long-double -std=c11",
    "-m96bit-long-double -std=c99",
    "-m96bit-long-double -std=c17",
    "-m96bit-long-double -std=c90",
    "-m96bit-long-double -std=gnu11",
    "-m96bit-long-double -std=gnu99",
    "-m96bit-long-double -std=gnu17",
    "-m96bit-long-double -std=gnu90",
    "-m96bit-long-double -std=gnu11 -trigraphs",
    "-m96bit-long-double -std=gnu99 -trigraphs",
    "-m96bit-long-double -std=gnu17 -trigraphs",
    "-m96bit-long-double -std=gnu90 -trigraphs",
    "-mlong-double-64 -std=c11",
    "-mlong-double-64 -std=c99",
    "-mlong-double-64 -std=c17",
    "-mlong-double-64 -std=c90",
    "-mlong-double-64 -std=gnu11",
    "-mlong-double-64 -std=gnu99",
    "-mlong-double-64 -std=gnu17",
    "-mlong-double-64 -std=gnu90",
    "-mlong-double-64 -std=gnu11 -trigraphs",
    "-mlong-double-64 -std=gnu99 -trigraphs",
    "-mlong-double-64 -std=gnu17 -trigraphs",
    "-mlong-double-64 -std=gnu90 -trigraphs",
    "-mavx -std=c11",
    "-mavx -std=c99",
    "-mavx -std=c17",
    "-mavx -std=c90",
    "-mavx -std=gnu11",
    "-mavx -std=gnu99",
    "-mavx -std=gnu17",
    "-mavx -std=gnu90",
    "-mavx -std=gnu11 -trigraphs",
    "-mavx -std=gnu99 -trigraphs",
    "-mavx -std=gnu17 -trigraphs",
    "-mavx -std=gnu90 -trigraphs",
    "-mavx -m96bit-long-double -std=c11",
    "-mavx -m96bit-long-double -std=c99",
    "-mavx -m96bit-long-double -std=c17",
    "-mavx -m96bit-long-double -std=c90",
    "-mavx -m96bit-long-double -std=gnu11",
    "-mavx -m96bit-long-double -std=gnu99",
    "-mavx -m96bit-long-double -std=gnu17",
    "-mavx -m96bit-long-double -std=gnu90",
    "-mavx -m96bit-long-double -std=gnu11 -trigraphs",
    "-mavx -m96bit-long-double -std=gnu99 -trigraphs",
    "-mavx -m96bit-long-double -std=gnu17 -trigraphs",
    "-mavx -m96bit-long-double -std=gnu90 -trigraphs",
    "-mavx -mlong-double-64 -std=c11",
    "-mavx -mlong-double-64 -std=c99",
    "-mavx -mlong-double-64 -std=c17",
    "-mavx -mlong-double-64 -std=c90",
    "-mavx -mlong-double-64 -std=gnu11",
    "-mavx -mlong-double-64 -std=gnu99",
    "-mavx -mlong-double-64 -std=gnu17",
    "-mavx -mlong-double-64 -std=gnu90",
    "-mavx -mlong-double-64 -std=gnu11 -trigraphs",
    "-mavx -mlong-double-64 -std=gnu99 -trigraphs",
    "-mavx -mlong-double-64 -std=gnu17 -trigraphs",
    "-mavx -mlong-double-64 -std=gnu90 -trigraphs",
    "-mavx512vpopcntdq -std=c11",
    "-mavx512vpopcntdq -std=c99",
    "-mavx512vpopcntdq -std=c17",
    "-mavx512vpopcntdq -std=c90",
    "-mavx512vpopcntdq -std=gnu11",
    "-mavx512vpopcntdq -std=gnu99",
    "-mavx512vpopcntdq -std=gnu17",
    "-mavx512vpopcntdq -std=gnu90",
    "-mavx512vpopcntdq -std=gnu11 -trigraphs",
    "-mavx512vpopcntdq -std=gnu99 -trigraphs",
    "-mavx512vpopcntdq -std=gnu17 -trigraphs",
    "-mavx512vpopcntdq -std=gnu90 -trigraphs",
    "-mavx512vpopcntdq -m96bit-long-double -std=c11",
    "-mavx512vpopcntdq -m96bit-long-double -std=c99",
    "-mavx512vpopcntdq -m96bit-long-double -std=c17",
    "-mavx512vpopcntdq -m96bit-long-double -std=c90",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu11",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu99",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu17",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu90",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu11 -trigraphs",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu99 -trigraphs",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu17 -trigraphs",
    "-mavx512vpopcntdq -m96bit-long-double -std=gnu90 -trigraphs",
    "-mavx512vpopcntdq -mlong-double-64 -std=c11",
    "-mavx512vpopcntdq -mlong-double-64 -std=c99",
    "-mavx512vpopcntdq -mlong-double-64 -std=c17",
    "-mavx512vpopcntdq -mlong-double-64 -std=c90",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu11",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu99",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu17",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu90",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu11 -trigraphs",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu99 -trigraphs",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu17 -trigraphs",
    "-mavx512vpopcntdq -mlong-double-64 -std=gnu90 -trigraphs",
  };
  unsigned i = value >> 19;
  if (i >= 108) {
    printf("-invalid\n");
    return;
  }
  printf("%s", a[i]);
  if (((value & 16) == 0) && ((i % 36) < 12)) {
    printf(" -m128bit-long-double");
  }
  printf("\n");
}

#include "return_value.c"

void print_value(void) {
  printf("%d\n", return_value());
}

int main(int argc, const char **argv) {
  if (argc == 1) {
    print_value();
  }
  else {
    print_cmd(argv[1]);
  }
  return 0;
}
