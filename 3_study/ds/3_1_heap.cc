/**
 * 堆
 * down:
 * up:
 * init:
 *
 */
#include <vector>
#include <iostream>

using namespace std;

class Heap {
public:

    void add(int n) {
        items.emplace_back(n);
        up(items.size()-1);
    }

    int pop() {
        int res = items[0];
        swap(items[0], items[items.size()-1]);
        items.pop_back();
        down(0, items.size());
        return res;
    }

    bool isEmpty() {
        return items.empty();
    }

private:
    void down(int n, int boundary) {
        while (true) {
            // 临界条件
            int left = 2 * n + 1;
            if (left >= boundary || left <= 0) {
                return;
            }

            //　挑选两个子节点中较小者
            int i = left;
            int right = left + 1;
            if (right < boundary && items[left] > items[right]) {
                i = right;
            }

            //　比较　＆＆　交换
            if (items[i] < items[n]) {
                swap(items[i], items[n]);
            }

            n = i;
        }
    }

    void up(int n) {
        while (true) {
            // 临界条件
            if (n <= 0) {
                return;
            }

            //　比较交换
            int parent = (n-1) / 2;
            if (items[parent] > items[n]) {
                swap(items[parent], items[n]);
            }

            n = parent;
        }
    }

    void init() {
        int length = items.size();
        for (int i = length/2-1; i>=0; i--) {
            down(i, length);
        }
    }

private:
    vector<int> items;
};

int main() {
    Heap h;
    h.add(5);
    h.add(4);
    h.add(6);
    h.add(2);
    h.add(1);
    h.add(19);
    h.add(100);

    while (!h.isEmpty()) {
        cout << h.pop() << endl;
    }
}