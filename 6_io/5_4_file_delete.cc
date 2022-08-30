//
// Created by wangyunlong01 on 2022/4/19.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filePath = "kafka.txt";
    if (remove(filePath.data()) == 0) {
        cout << "delete success\n";
    } else {
        cout << "delete failed\n";
    }
}