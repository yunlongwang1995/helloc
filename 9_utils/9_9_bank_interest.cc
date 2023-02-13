//
// Created by wangyunlong01 on 2022/6/17.
//

#include <iostream>
#include <math.h>

/**
 * 等额 贷款计算
 * @param total_loans     总贷款　
 * @param interest_rate   月利率
 * @param num_of_issues   月期数
 *
 * @return pay_per_issue  每月（期）还款数
 */
double CalPayPerIssue(double total_loans, double interest_rate, int num_of_issues) {
    double pay_per_issue = 0.0;
    pay_per_issue = total_loans * interest_rate * (1 + 1 / (pow(1 + interest_rate, num_of_issues - 1) - 1));
    return pay_per_issue;
}

int main() {
//    double total_loans = 1200000;

    // 2021.9 - 2022.8
//    double total_loans = 1218639.32;
//    double interest_rate = 5.4 * 0.01 / 12;
//    int num_of_issues = 30 * 12;

    // 2022.9 - 2023.8
//    double total_loans = 1201813.22;
//    double interest_rate = 5.05 * 0.01 / 12;
//    int num_of_issues = 29 * 12;

    // 假设 2023.05.04 提前还款 40w
    double total_loans = (122 - 3 - 40) * 10000;
    double interest_rate = 5.05 * 0.01 / 12;
    int num_of_issues = 29 * 12 - 9;

    double res = CalPayPerIssue(total_loans, interest_rate, num_of_issues);
    std::cout << "每月还款：" << res << std::endl;
}
