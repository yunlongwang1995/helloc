#include <iostream>

using namespace std;

#define TOSTR1(_FILENAME_) #_FILENAME_
#define TOSTR2(_FILENAME_,_SUFFIX_) #_FILENAME_"."#_SUFFIX_

int main() {
  cout << TOSTR1(cloud) << endl;
  cout << TOSTR2(cloud, txt) << endl;
  return 0;
}
