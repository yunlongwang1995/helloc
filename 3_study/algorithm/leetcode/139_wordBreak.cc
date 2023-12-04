/**
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 *
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 */

#include "../../base.h"

bool dfs(const string& s, const unordered_map<string, bool>& dict, int startIndex) {
  // 基准情况
  if (startIndex == s.length()) {
    return true;
  }

  // 遍历
  for (int i=startIndex+1; i<s.length(); ++i) {
    string subString = s.substr(startIndex, i);
    if (dict.at(subString)) {
      return dfs(s, dict, i);
    }
  }

  return false;
}

// method1: backtracing
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_map<string, bool> dict;
  for (auto item: wordDict) {
    dict[item] = true;
  }
  return dfs(s, dict, 0);
}

int main() {

}

// method2: dp
bool wordBreak2(string s, vector<string>& wordDict) {
  // 初始化
  bool dp[s.length()+1];
  for (int i=0; i<=s.length(); ++i) {
    dp[i] = false;
  }
  dp[0] = true;

  unordered_map<string, bool> dict;
  for (auto item: wordDict) {
    dict[item] = true;
  }

  for (int i=1; i<=s.length(); ++i) {
    for (int j=i; j>=0; --j) {
      string subString = s.substr(j, i+1);
      if (dict.at(subString) && dp[j-1]) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[s.length()-1];
}