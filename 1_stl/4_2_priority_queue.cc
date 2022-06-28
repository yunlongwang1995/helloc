//
// Created by wangyunlong01 on 2022/6/22.
//
#include <queue>
#include <iostream>

using namespace std;

int main() {
    vector<int> list = {5, 4, 6, 4, 1};

    // 1. 默认最大堆
    priority_queue<int> queue;
    for (auto item: list) {
        queue.push(item);
    }
    cout << "默认优先队列（最大堆）：";
    while (!queue.empty()) {
        cout << queue.top() << " ";
        queue.pop();
    }

    // 2. 最小堆
    priority_queue<int, vector<int>, greater<int>> queue2;
    for (auto item: list) {
        queue2.push(item);
    }
    cout << "\ngreater 优先队列：";
    while (!queue2.empty()) {
        cout << queue2.top() << " ";
        queue2.pop();
    }
}