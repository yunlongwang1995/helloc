//
// Created by wangyunlong01 on 2022/7/1.
//

#include "common.h"

void hello(int n, bool **matrix) {
    matrix[n - 1][n] = true;
}

void one_dimension() {
    int n = 5;
    bool *matrix;
    bool item[n];
    for (int j = 0; j < n; j++) {
        item[j] = false;
    }
    matrix = item;

    for (int i = 0; i < n; ++i) {
        cout << matrix[i] << " ";
        cout << endl;
    }
}

void two_dimension() {
    int n = 5;
    bool *matrix[n];
    for (int i = 0; i < n; i++) {
        bool *item = new bool[n];
        for (int j = 0; j < n; j++) {
            item[j] = false;
        }
        matrix[i] = item;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<n; ++i) {
        delete[] matrix[i];
    }
}

int main() {
//    one_dimension();
    two_dimension();
}

