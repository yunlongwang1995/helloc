/**
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "../../common.h"

LNode* removeRepeatedNum(LNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    LNode* newHead = nullptr;
    LNode* left = nullptr;
    LNode* middle = nullptr;
    LNode* right = nullptr;
    LNode* p = head->next;
    int count = 0;

    //1: find new head node
    while (true) {
        if (p == nullptr) {
            if (count == 0) {
                return head;
            }
            return nullptr;
        }
        if (head->val == p->val) {
            p = p->next;
            count++;
            continue;
        }

        if (count==0) {
            newHead = head;
            left = head;
            middle = p;
            left->next = middle;
            break;
        }
        head = p;
        p = head->next;
    }

    //2: remove repeated node
    right = middle->next;
    count = 0;
    while (true) {
        if (right == nullptr) {
           if (count != 0) {
               left->next = nullptr;
           }
           break;
        }

        if (middle->val == right->val) {
            right = right->next;
            count++;
            continue;
        }

        if (count == 0) {
            left = middle;
            middle = right;
            left->next = middle;
            continue;
        }

        middle = right;
        left->next = middle;
        right = middle->next;
    }

    return newHead;
}

int main() {

}