/**
 *
 *
 *
 */

#include "../../common.h"

bool isSymmetricHelp(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr) {
        return false;
    }
    if (right == nullptr) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }

    if (isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left)) {
        return true;
    }

    return false;
}

bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    return isSymmetricHelp(root->left, root->right);
}


int main() {

}