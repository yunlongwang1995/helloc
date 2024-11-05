/**
 * 找出字符串中第一个匹配项的下标
 *
 *
 */

#include "../../../base.h"

using namespace std;

bool compare_size_str(string& hay, int start, string& needle) {
  for (int i=0; i<needle.length(); ++i) {
    if (hay[start+i] != needle[i]) {
      return false;
    }
  }

  return true;
}

int strStr(string haystack, string needle) {
  int hay_len = haystack.length();
  int needle_len = needle.length();
  if (hay_len < needle_len) {
    return -1;
  }

  for (int i=0; i<=hay_len-needle_len; ++i) {
    if (compare_size_str(haystack, i, needle)) {
      return i;
    }
  }

  return -1;
}

int main() {

}
