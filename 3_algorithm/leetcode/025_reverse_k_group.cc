/**
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseGroup(ListNode* head, ListNode* rear, ListNode** newHead, ListNode** newRear) {
    *newHead = rear;
    *newRear = head;
    ListNode* p = head;
    head = head->next;
    while (p != rear) {
       p->next = rear->next;
       rear->next = p;
       p = head;
       head = head->next;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 1) {
        return head;
    }

    ListNode* res = head;
    ListNode* tempRear;
    ListNode* nextGroupHead;
    ListNode* newHead;
    ListNode* newRear;
    ListNode* left;
    ListNode* right;
    ListNode* p = head;
    int n = 0;
    while (p) {
        if (n == 0) {
            left = p;
        }
        n++;

        if (n == k) {
            right = p;
            n = 0;
            nextGroupHead = p->next;
            reverseGroup(left, right, &newHead, &newRear);
            if (res == head) {
                res = newHead;
                tempRear = newRear;
            } else {
                tempRear->next = newHead;
                tempRear = newRear;
            }

            p = nextGroupHead;
            continue;
        }

        p = p->next;
    }

    return res;
}

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);
    ListNode n5 = ListNode(5);
    ListNode n6 = ListNode(6);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode* head = reverseKGroup(&n1, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}