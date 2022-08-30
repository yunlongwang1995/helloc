//
// Created by wangyunlong01 on 2022/4/19.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("kafka.txt", ios::app);
    if (myFile.is_open()) {
        cout << "file is created" << endl;
    }
}