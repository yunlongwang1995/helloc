//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：
 * sort()
 * stable_sort()
 *
 * 快排与归并排序
 * 时间复杂度：Nlog(N)
 */

/**
 * sort() 底层是快排
 * sort() 函数受到底层实现方式的限制，它仅适用于普通数组和部分类型的容器。
 * 换句话说，只有普通数组和具备以下条件的容器，才能使用 sort() 函数：
 * 1: 容器支持的迭代器类型必须为随机访问迭代器。这意味着，sort() 只对 array、vector、deque 这 3 个容器提供支持。
 * 2: 如果对容器中指定区域的元素做默认升序排序，则元素类型必须支持<小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
 * 3: sort() 函数在实现排序时，需要交换容器中元素的存储位置。这种情况下，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数和移动赋值运算符。
 */

/**
 * stable_sort() 底层是归并排序
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> values{1,9,5,1,7,36,7};
    sort(values.begin(), values.end());
    sort(values.begin(), values.end(), greater<int>());
    cout << "sort 排序后: ";
    for (int item: values) {
        cout << item << "  ";
    }

    stable_sort(values.begin(), values.end());
    cout << endl << "stable_sort 排序后: ";
    for (int item: values) {
        cout << item << "  ";
    }
}