/**
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 *
 */

#include <iostream>
#include <string>
using namespace std;

int reverse(int x) {
    long res = 0;
    while (x != 0) {
        res = res*10 + x%10;
        x = x/10;
    }

    return int(res)==res? int(res):0;
}


int main() {
    cout << reverse(6294) << endl;
}