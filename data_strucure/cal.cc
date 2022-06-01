#include <iostream>
#include <algorithm>
#include <stack>
#include <map>


using namespace std;

void print_erro(string s,int line) {
    cout << s <<" " << line << endl;
    exit(-1);
}

void calculate(stack<int> &num_stak, stack<char> &oper_stack) {
    int num1;
    int num2;
    int result;

    num1 = num_stak.top();
    num_stak.pop();
    num2 = num_stak.top();
    num_stak.pop();

    if (oper_stack.top() == '+') {
        result = num1 + num2;
    } else if (oper_stack.top() == '-') {
        result = -(num1 - num2);
    } else if (oper_stack.top() == '*') {
        result = num1 * num2;
    } else if (oper_stack.top() == '/') {
        if (num1 == 0) {
            print_erro("divide num is 0 \n", __LINE__);
        }
        result = num2 / num1;
    } else {
        print_erro("operator failed\n", __LINE__);
    }
    oper_stack.pop();
    num_stak.push(result);
}

int state_change(string s) {
    static const int BEGIN_STATE = 0;
    static const int NUM_STATE = 1;
    static const int OPE_STATE = 2;
    int STATE = BEGIN_STATE;
    map<char,int> prio;
    stack<int> num_stack;
    stack<char> oper_stack;

    int cacl_flag = -1;
    int number = 0;
    prio['+'] = 1;
    prio['-'] = 1;
    prio['*'] = 2;
    prio['/'] = 2;
    prio['('] = 3;

    int i;
    if (s.empty()) {
        print_erro("string is empty\n",__LINE__);
    }

    for(int i = 0;i < s.size(); ++i) {
        if (s[i] == ' ') {
            continue;
        }
        switch (STATE)
        {
            case BEGIN_STATE:
                if (s[i] >= '0' && s[i] <= '9') {
                    STATE = NUM_STATE;
                } else if(s[i] == ')'){
                    print_erro("string is not leagal\n",__LINE__);
                } else {
                    STATE = OPE_STATE;
                }
                i--;
                break;

            case NUM_STATE:
                if (s[i] >= '0' && s[i] <= '9') {
                    number = number*10 + s[i] - '0';
                } else {
                    num_stack.push(number);
                    if (cacl_flag == 2) {
                        calculate(num_stack,oper_stack);
                    }
                    STATE = OPE_STATE;
                    number = 0;
                    i--;
                }
                break;

            case OPE_STATE:
                if(prio[s[i]] == 1) {
                    oper_stack.push(s[i]);
                    cacl_flag = 1;
                } else if(prio[s[i]] == 2) {
                    oper_stack.push(s[i]);
                    cacl_flag = 2;
                } else if (prio[s[i]] == 3) {
                    cacl_flag = 3;
                    STATE = NUM_STATE;
                    break;
                } else if (s[i] == ')') {
                    calculate(num_stack,oper_stack);
                    break;
                } else if(s[i] >= '0' && s[i] <= '9') {
                    STATE = NUM_STATE;
                    i--;
                } else {
                    print_erro("string is not leagal \n",__LINE__);
                }

                break;

            default:
                break;
        }
    }

    if (number != 0) {
        num_stack.push(number);
        calculate(num_stack,oper_stack);
    }

    if (number == 0 && num_stack.empty()) {
        return 0;
    }
    while(!oper_stack.empty() && num_stack.size() != 1) {
        calculate(num_stack,oper_stack);
    }

    if (!oper_stack.empty()) {
        print_erro("string is not leagal", __LINE__);
    }

    return num_stack.top();
}

int main() {
    string s;
    cout << "input the string " << endl;
    cin >> s;
    int a = state_change(s);
    cout << "calcute the result is " << a << endl;
    return 0;
}
