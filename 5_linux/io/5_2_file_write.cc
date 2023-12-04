//
// Created by wangyunlong01 on 2022/4/19.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("kafka.txt", ios::out | ios::app);
    if (myFile.is_open()) {
        cout << "file is opened" << endl;
        myFile << "hello c++\n";
        myFile << "this is second line\n";
        myFile.flush();   // flush to page cache
        myFile.sync();    // sync data from page cache to disk
        myFile.close();
    }
}