//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：
 * copy:
 * copy_n
 * copy_if
 * copy_backward: 从最后一个元素开始直到第一个元素
 * reverse_copy:
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int i) {
    cout << i << " ";
}

int main() {
    vector<int> values = {1,2,3,4,5,6,7,8,9};
    vector<int> des;

    des.resize(values.size());
    copy(values.begin(), values.end(), des.begin());

    for_each(des.begin(), des.end(), print);
}