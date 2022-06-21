//
// Created by wangyunlong01 on 2022/4/13.
//

#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    // 初始化
    vector<int> values;
    values.push_back(1);
    values.insert(values.begin(), 2);
    values.insert(values.begin(), 3);
    values.push_back(4);

    cout << "正向遍历： ";
    for (auto item: values) {
        cout << item << "  ";
    }

    cout << endl;
    cout << values[100] << endl;     // 不抛异常
    cout << values.at(3) << endl;  // 抛 std::out_of_range 异常

    cout << endl << "删除" << endl;
    values.erase(++values.begin());

    cout << "正向遍历： ";
    for (auto item: values) {
        cout << item << "  ";
    }
}