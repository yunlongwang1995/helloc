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

bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == targetSum) {
            return true;
        }
        return false;
    }

    if (root->left == nullptr) {
        return hasPathSum(root->right, targetSum - root->val);
    }
    if (root->right == nullptr) {
        return hasPathSum(root->left, targetSum - root->val);
    }

    for (int i = 0; i < 2; ++i) {
        if (i == 0) {
            if (hasPathSum(root->left, targetSum - root->val)) {
                return true;
            }
            continue;
        }
        return hasPathSum(root->right, targetSum - root->val);
    }

    return false;
}

int main() {

}