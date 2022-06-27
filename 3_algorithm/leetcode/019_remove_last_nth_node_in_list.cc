/**
 * 删除链表的倒数第 N 个结点
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode *head, int n) {
    // 只有一个节点
    if (head->next == nullptr) {
        return nullptr;
    }

    int step = 0;
    bool isDeleteHead = false;
    ListNode *f = head;
    ListNode *r = head;
    while (step < n) {
        f = f->next;
        step++;
    }

    // 删除头节点
    if (f == nullptr) {
        head = head->next;
        return head;
    }

    // 删除非头节点
    while (f->next) {
        r = r->next;
        f = f->next;
    }
    r->next = r->next->next;

    return head;
}

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    ListNode* res = removeNthFromEnd(&n1, 2);
    ListNode* p = res;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
}