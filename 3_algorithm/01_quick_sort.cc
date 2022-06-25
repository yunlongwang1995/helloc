/**
 * 思想
 * 1.在待排序的元素任取一个元素作为基准(通常选第一个元素，但最的选择方法是从待排序元素中随机选取一个作为基准)，称为基准元素；
 * 2.将待排序的元素进行分区，比基准元素大的元素放在它的右边，比其小的放在它的左边；
 * 3.对左右两个分区重复以上步骤直到所有元素都是有序的。
 *
 * 时间复杂度：最好 Nlog(N),　平均 Nlog(N)，　最坏情况：O(n2)
 * 空间复杂度：log(N); 递归栈最大深度：log(N)+1
 *
 */

#include <iostream>
using namespace std;

/**
 *
 * @param arr
 * @param cLeft   左边界（包含）
 * @param cRight  右边界（包含）
 */
void QuickSort(int arr[], int cLeft, int cRight) {
    // 基准条件
    if (cLeft >= cRight) {
        return;
    }

    int left = cLeft;
    int right = cRight;

    // 分区排序
    int base = arr[left];
    while (left < right) {
        while (right > left && arr[right] >= base) {
            right--;
        }
        arr[left] = arr[right];

        while (left < right && arr[left] <= base) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = base;

    QuickSort(arr, cLeft, left - 1);
    QuickSort(arr, left+1, cRight);
}

int main() {
    int arr[] = {5,7,1,9,4, 45, 62, 4, 8, 24};
    cout << "排序前：";
    for (int item: arr) {
        cout << item << "  ";
    }

    QuickSort(arr, 0,sizeof(arr)/sizeof(int)-1);

    cout << "\n排序后：";
    for (int item: arr) {
        cout << item << "  ";
    }
}