//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：
 * merge 采用拷贝方式，对原数组无影响
 * inplace_merge 在原数组进行原地 merge
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10, 20};
    vector<int> values(11);
    merge(a, a+5, b, b+6, values.begin());
    cout << "merge 后: ";
    for (int item: values) {
        cout << item << "  ";
    }

    // 该数组中存储有 2 个有序序列
    int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };
    // 将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列。
    inplace_merge(first, first + 5,first +11);
    cout << endl << "inplace_merge 后: ";
    for (int i = 0; i < 11; i++) {
        cout << first[i] << "  ";
    }
}