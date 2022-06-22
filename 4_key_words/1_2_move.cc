//
// Created by wangyunlong01 on 2022/5/11.
//

#include <iostream>

using namespace std;

class Group {

public:
    Group() {
        cout << "default construct" << endl;
        size = 100;
    }

    Group(const Group &group) : size(group.size) {
        cout << "copy construction" << endl;
    }

    Group(const Group &&group) : size(group.size) {
        cout << "move construction" << endl;
    }

    Group operator=(const Group &group) {
        cout << "operator=" << endl;
        return group;
    }

    ~Group() {
        cout << "deconstruction" << endl;
    }

public:
    int size;
};

Group GetGroup() {
    Group g;
    return g;
}

int main() {
    Group *g1 = new Group();
    cout << g1 << endl;

    Group&& g2 = move(*g1);
    cout << &g2 << endl;
    cout << g1 << endl;
//    delete g1;
    delete &g2;
}