//
// Created by wangyunlong01 on 2022/6/22.
//
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> values;
    back_insert_iterator<list<int>> inserter(values);
    inserter = 1;
    inserter = 2;
    inserter = 3;
    inserter = 4;

    cout << "数据：";
    for (auto item: values) {
        cout << item << "  ";
    }
}
