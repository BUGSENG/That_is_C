/*
  Copyright (c) 2019-2023 BUGSENG srl
  See LICENSE.txt for details.
*/

#include <stdio.h>
#include <stdlib.h>

void print_cmd(const char *arg) {
  char *endptr;
  long value = strtol(arg, &endptr, 10);
  if (*endptr != '\0') {
    printf("invalid argument\n");
    return;
  }
  if (value < 0 || value > 767) {
    printf("argument not in range 0..767\n");
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
  const char *a1[]
    = { "-std=c11", "-std=c99", "-std=c17", "-std=c90",
        "-std=gnu11", "-std=gnu99", "-std=gnu17", "-std=gnu90",
        "-std=gnu11 -trigraphs", "-std=gnu99 -trigraphs",
        "-std=gnu17 -trigraphs", "-std=gnu90 -trigraphs",
        "-invalid", "-invalid", "-invalid", "-invalid",
  };
  printf("%s\n", a1[(value & 960) >> 6]);
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
