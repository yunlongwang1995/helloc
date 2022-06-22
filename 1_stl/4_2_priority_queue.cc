//
// Created by wangyunlong01 on 2022/6/22.
//
#include <queue>
#include <iostream>

using namespace std;

int main() {
    priority_queue<int> queue;
    queue.push(5);
    queue.push(4);
    queue.push(6);
    queue.push(1);

    cout << queue.top() << endl;
}