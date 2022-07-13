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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int size = q.size();
        for (int i=0; i<size; ++i) {
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