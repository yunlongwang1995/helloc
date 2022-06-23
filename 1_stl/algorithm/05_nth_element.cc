//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录:
 * nth_element
 * 时间复杂度：O(n)
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> values = { 3,2,5,4,1,6,9,7};
    nth_element(values.begin(), values.begin()+4, values.end());
    cout << "nth_element 排序后: ";
    for (int item: values) {
        cout << item << "  ";
    }
}