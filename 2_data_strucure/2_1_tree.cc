//
// Created by wangyunlong01 on 2022/6/1.
//

#include <iostream>
#include <queue>

class TNode {
public:
    TNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
public:
    int val;
    TNode* left;
    TNode* right;
};

// 先序遍历
void PreorderTraversal(TNode* root) {
    if (!root) {
        return;
    }
    std::cout << root->val << "  ";
    if (root->left) {
        PreorderTraversal(root->left);
    }
    if (root->right) {
        PreorderTraversal(root->right);
    }
}

// 中序遍历
void MidOrderTraversal(TNode* root) {
    if (!root) {
        return;
    }

    if (root->left) {
        MidOrderTraversal(root->left);
    }
    std::cout << root->val << "  ";
    if (root->right) {
        MidOrderTraversal(root->right);
    }
}

// 后序遍历
void PostorderTraversal(TNode* root) {
    if (!root) {
        return;
    }

    if (root->left) {
        PostorderTraversal(root->left);
    }
    if (root->right) {
        PostorderTraversal(root->right);
    }
    std::cout << root->val << "  ";
}

// 广度遍历
void bfs(TNode* root) {
    if (!root) {
        return;
    }

    std::queue<TNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TNode* head = queue.front();
        if (head->left) {
            queue.push(head->left);
        }
        if (head->right) {
            queue.push(head->right);
        }
        std::cout << head->val << "  ";
        queue.pop();
    }
}

int main() {
    TNode n1(1);
    TNode n2(2);
    TNode n3(3);
    TNode n4(4);
    TNode n5(5);

    n3.left = &n1;
    n3.right = &n5;
    n1.right = &n2;
    n5.left = &n4;

    std::cout << "先序遍历" << std::endl;
    PreorderTraversal(&n3);

    std::cout << std::endl << "中序遍历" << std::endl;
    MidOrderTraversal(&n3);

    std::cout << std::endl << "后序遍历" << std::endl;
    PostorderTraversal(&n3);

    std::cout << std::endl << "广度遍历" << std::endl;
    bfs(&n3);
}

