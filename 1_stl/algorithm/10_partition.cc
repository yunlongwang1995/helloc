//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：
 * partition:　只负责分区，不负责相对位置
 * stable_partition: 既负责分区，也保证相对位置
 * partition_copy: 不破坏老数据
 * partition_point: 找出已经分区数组的分界点，类似于 find_if 函数
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int i) {return i%2 == 1;}

int main() {
    // partition
    vector<int> values{11,12,13,14,15,16,17,18,19};
    auto it = partition(values.begin(), values.end(), comp);
    cout << "bound = " << *it << endl;
    cout << "partition后：";
    for (auto item: values) {
        cout << item << "  ";
    }

    // stable_partition
    vector<int> values2{11,12,13,14,15,16,17,18,19};
    auto it2 = stable_partition(values2.begin(), values2.end(), comp);
    cout << "\n\nbound = " << *it2 << endl;
    cout << "stable_partition后: ";
    for (auto item: values2) {
        cout << item << "  ";
    }

    // partition_copy
    vector<int> v1{11,12,13,14,15,16,17,18,19};
    int v2[10];
    int v3[10];
    auto result = partition_copy(v1.begin(), v1.end(), v2, v3, comp);
    cout << "\n\nb[10]：";
    for (int *p = v2; p < result.first; p++) {
        cout << *p << " ";
    }
    cout << "\nc[10]：";
    for (int *p = v3; p < result.second; p++) {
        cout << *p << " ";
    }

    // partition_point


}