//
// Created by wangyunlong01 on 2022/4/13.
//

#include <vector>
#include <iostream>

using namespace std;

// print point of vector
void printPrt(int* in);

// case1: copy
void testCopy();

int main(int argc, char **argv) {
    testCopy();
}

// case1: copy
void testCopy(){
    vector<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    vector<int> l2 = l1;

    printPrt(&l1[0]);
    printPrt(&l2[0]);
}

void printPrt(int* in) {
    printf("%u\n", in);
}


