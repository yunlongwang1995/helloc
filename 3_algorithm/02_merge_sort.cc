/**
 * 归并排序
 * 时间复杂度：
 * 空间复杂度：
 *
 */

#include <iostream>
using namespace std;

void Merge(int arr[], int left, int middle, int right) {
    int first = left;
    int second = middle;

    int temp[right - left + 1];
    int p = 0;
    while (first < middle && second <= right) {
        if (arr[first] <= arr[second]) {
            temp[p++] = arr[first++];
        } else {
            temp[p++] = arr[second++];
        }
    }

    while (first < middle) {
        temp[p++] = arr[first++];
    }
    while (second <= right) {
        temp[p++] = arr[second++];
    }

    for (int i=0; i < right-left+1; i++) {
        arr[left + i] = temp[i];
    }
}

/**
 *
 * @param arr
 * @param left   // 左边界（包含）
 * @param right  // 右边界（包含）
 */
void MergeSort(int arr[], int left, int right) {
    // 基准情况
    if (left >= right) {
        return;
    }

    // 分割
    MergeSort(arr, left, (left + right) / 2);
    MergeSort(arr, (left + right) / 2 + 1, right);

    // 归并
    Merge(arr, left, (left + right) / 2 + 1, right);
}

int main() {
    int arr[] = {5,7,1,9,4, 45, 62, 4, 8, 24};
    cout << "排序前：";
    for (int item: arr) {
        cout << item << "  ";
    }

    MergeSort(arr,0, sizeof(arr)/sizeof(int)-1);

    cout << "\n排序后：";
    for (int item: arr) {
        cout << item << "  ";
    }
}