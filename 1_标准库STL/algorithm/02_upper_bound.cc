//
// Created by wangyunlong01 on 2022/6/22.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool mycmp(int i, int j) {
    return i > j;
}

int main() {
    // 查找[first, last)区域中第一个大于 val 的元素。
    vector<int> values = {1,3,5,9,10};
    auto p = upper_bound(values.begin(), values.end(), 5);
    cout << "p = " << *p << endl;

    // 在 [first, last) 区域内查找第一个不符合 comp 规则的元素
    vector<int> values2 = {15, 12,6,10,5};
    auto p2 = upper_bound(values2.begin(), values2.end(), 7, mycmp);
    cout << "p2 = " << *p2 << endl;
}