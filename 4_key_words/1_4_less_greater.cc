//
// Created by wangyunlong01 on 2022/6/28.
//
#include <iostream>
#include <queue>
using namespace std;

class Person1_4 {
public:
    Person1_4() {}
    Person1_4(string name, int age) : name_(name), age_(age){
    }

    bool operator<(Person1_4 &p) {
        return this->age_ < p.age_;
    }

    bool operator>(Person1_4 &p) {
        return this->age_ > p.age_;
    }

public:
    string name_;
    int age_;
};

class Comp1_4 {
public:
    bool operator()(const Person1_4& l, const Person1_4& r) {
        return l.age_ > r.age_;
    }
};

int main() {
    // 1.比较大小
    Person1_4 p1 = Person1_4("111", 11);
    Person1_4 p2 = Person1_4("222", 22);
    Person1_4 p3 = Person1_4("000", 9);
    Person1_4 p4 = Person1_4("000", 11);

    bool isLess = p1 < p3;
    cout << isLess << endl;

    bool isGreater = p1 > p3;
    cout << isGreater << endl;

    // 2.优先队列
    priority_queue<Person1_4, vector<Person1_4>, Comp1_4> queue;
    queue.push(p1);
    queue.push(p2);
    queue.push(p3);
    queue.push(p4);
    while (!queue.empty()) {
        cout << queue.top().age_ << " ";
        queue.pop();
    }
}
