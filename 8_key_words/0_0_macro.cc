#include "../base.h"


#define TOSTR1(_FILENAME_) #_FILENAME_
#define TOSTR2(_FILENAME_, _SUFFIX_) #_FILENAME_"."#_SUFFIX_

/**
 * #: 转字符串
 */
void ToStringTest();


#define IdentCAT(_IDT1_, _IDT2_) my_##_IDT1_##_##_IDT2_
#define TOSTR(_NAME_) #_NAME_" = "

/**
 * ##: 转标识符
 */
void IdentCatTest();

int main() {
  ToStringTest();
  cout << "----------------------" << endl;
  IdentCatTest();
}

void ToStringTest() {
  cout << TOSTR1(cloud) << endl;
  cout << TOSTR2(cloud, txt) << endl;
}

void IdentCatTest() {
  int IdentCAT(first, bag) = 1;
  int IdentCAT(second, bag) = 18;
  cout << TOSTR(my_first_bag) << IdentCAT(first, bag) << endl;
  cout << TOSTR(my_second_bag) << IdentCAT(second, bag) << endl;
}