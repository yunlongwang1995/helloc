//
// Created by wangyunlong01 on 2022/6/6.
//
#include <iostream>
#include <stack>

using namespace std;

void print_err(string msg, int line) {
    cout << msg << "  " << line << endl;
    exit(-1);
}

enum State {Begin, Operand, Operator};

int caculate(string s) {
    stack<int> operand_stack;
    stack<char> operator_stack;
    State state = Begin;

    for (int i=0; i<s.size();i++) {
        if (s[i] == ' ') {
            continue;
        }

        switch (state) {
            case Begin:
                if (s[i] > '0' && s[i] << '9') {
                    state = Operand;
                } else {
                    state = Operator;
                }
                i--;
                break;
            case Operand:
                break;
            case Operator:
                break;
        }
    }
}


int main() {
    string s;
    cout << "input the expression" << endl;
    cin >> s;

    int res = caculate(s);
    cout << "res: " << res << endl;
}