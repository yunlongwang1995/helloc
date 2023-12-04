/**
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

 * 有效 二叉搜索树定义如下：
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 */

#include "../../../base.h"

bool isValidBST(TreeNode *root) {
    // 基准条件
    if (root == nullptr) {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    // 有节点
    if (root->left) {
        TreeNode *leftMax = root->left;
        while (leftMax->right) {
            leftMax = leftMax->right;
        }
        if (root->val <= leftMax->val) {
            return false;
        }
    }

    if (root->right) {
        TreeNode *rightMin = root->right;
        while (rightMin->left) {
            rightMin = rightMin->left;
        }
        if (root->val >= rightMin->val) {
            return false;
        }
    }

    return isValidBST(root->left) && isValidBST(root->right);
}

int main() {

}