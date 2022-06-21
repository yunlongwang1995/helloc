//
// Created by wangyunlong01 on 2022/6/21.
//

#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> values;
    values.push_back(5);
    values.push_back(4);
    values.push_back(3);
    values.push_back(6);

    values.sort();
    cout << "遍历： ";
    for (auto item: values) {
        cout << item << "  ";
    }
}