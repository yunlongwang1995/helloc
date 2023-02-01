//
// Created by wangyunlong01 on 2022/4/13.
//
#include <iostream>
#include "../base.h"

using namespace std;

typedef enum ErrCode {
  NotFound = 100,
  IsNil
}ErrCode;

#define XXX_NotFound "[%s] not found [%u]"
#define STRCAT(STR1, STR2) STR1##_##STR2

#define pp(code, ...) printf(STRCAT(XXX, code), ##__VA_ARGS__);

#define pp2(code, ...)    \
  {                       \
     string s1 = "code=%u ";        \
     string s2 = STRCAT(XXX, code); \
     string fmt = s1 + s2;         \
     printf(fmt, code, ##__VA_ARGS__);                     \
  }

int main(int argc, char** argv) {
  cout << STRCAT(XXX, NotFound) << endl;
  printf(STRCAT(XXX, NotFound), "table", 88);
  printf("\n");
  pp(NotFound, "kaka", 66);

  printf("\n");
  printf("code=%u", NotFound);

  pp(NotFound, "kaka", 66);
}

