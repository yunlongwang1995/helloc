#include <iostream>

using namespace std;

#define STRCAT1(_IDT1_,_IDT2_)  my_##IDT1_##_##_IDT2_
#define STRCAT2(_IDT1_,_IDT2_) my_##_IDT1_##_##_IDT2_
#define TOSTR(_NAME_) #_NAME_" = "

int main() {
  int STRCAT1(first, bag) = 0;
  int STRCAT2(second, bag) = 1;
  cout << TOSTR(my_first_bag) << STRCAT1(first, bag) << endl;
  cout << TOSTR(my_second_bag) << STRCAT2(second, bag) << endl;
  return 0;
}

