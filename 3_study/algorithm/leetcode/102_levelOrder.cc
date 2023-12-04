/**
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 *（即逐层地，从左到右访问所有节点）。
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 * 输入：root = []
 * 输出：[]
 */

#include "../../../base.h"

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto item = q.front();
            level.push_back(item->val);
            if (item->left) {
                q.push(item->left);
            }
            if (item->right) {
                q.push(item->right);
            }
            q.pop();
        }

        result.push_back(level);
    }

    return result;
}

int main() {

}