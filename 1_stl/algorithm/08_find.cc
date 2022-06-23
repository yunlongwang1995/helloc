//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：
 * find: 找不到则返回指向　last 迭代器
 * find_if: 返回第一个满足条件的
 * find_if_not: 返回第一个不满足条件的
 * find_end: 序列 A 中查找序列 B 最后一次出现的位置
 * find_first_of: A 序列中查找和 B 序列中任意元素相匹配的第一个元素
 * adjacent_find: 指定范围内查找 2 个连续相等的元素
 *
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool isOddNumber(int i) {
    return i%2 == 1;
}

int main() {
    // find
    char s1[] = "hello world";
    char *p = find(s1, s1 + strlen(s1), 'o');
    if (p != s1 + strlen(s1)) {
        cout << p << endl;
    }

    // find_if
    vector<int> values = {4,2,3,1,5};
    auto it = find_if(values.begin(), values.end(), isOddNumber);
    if (it != values.end()) {
        cout << "first odd number: " << *it << endl;
    }

    // find_if_not
    auto it2 = find_if_not(values.begin(), values.end(), isOddNumber);
    if (it2 != values.end()) {
        cout << "first not odd number: " << *it2 << endl;
    }

    // find_end
    int sub_array[] = {3, 1};
    auto it3 = find_end(values.begin(), values.end(), sub_array, sub_array+2);
    if (it3 != values.end()) {
        cout << "last sub array position: " << it3 - values.begin() << endl;
    }

}