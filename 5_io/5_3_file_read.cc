//
// Created by wangyunlong01 on 2022/4/19.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("kafka.txt", ios::in);
    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }
}