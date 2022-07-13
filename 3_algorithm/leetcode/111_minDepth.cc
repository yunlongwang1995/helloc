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

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    }

    if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    }

    int leftMinHeight = minDepth(root->left);
    int rightMinHeight = minDepth(root->right);

    int res = leftMinHeight<rightMinHeight? leftMinHeight:rightMinHeight;
    return res + 1;
}

int main() {

}