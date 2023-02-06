#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
  vector<int> nodes = {1, -1, 3, 4, 5, 6};
  auto num = nodes.size();
  if (num <= 1) {
    return 0;
  }

  vector<TreeNode*> node_list;
  for (auto elem: nodes) {
    node_list.emplace_back(&TreeNode(elem));
  }

  int idx = 0;
  for (auto n: node_list) {
    // left child: 2*n + 1
    int left_idx = 2 * idx + 1;
    if (left_idx >= num) {
      break;
    }
    node_list[idx]->left = node_list[left_idx];

    // right child: 2*n + 2
    int right_idx = 2 * idx + 2;
    if (left_idx >= num) {
      break;
    }
    node_list[idx]->right = node_list[right_idx];

    ++idx;
  }

  vector<int> sums = vector<int>(num);
  int result = 0;

  for (int i = num - 1; i >= 0; --i) {
    if (node_list[i] == nullptr) {
      sums[i] = 0;
      continue;
    }

    // 叶子节点
    if (2 * i + 1 >= num) {
      if (node_list[i]->val > 0) {
        sums[i] = node_list[i]->val;
      } else {
        sums[i] = 0;
      }
      continue;
    }

    // 非叶子节点
    int left_path_sum = sums[2 * i + 1];
    int right_path_sum = 0;
    if (2 * i + 2 < num) {
      right_path_sum = sums[2 * i + 2];
    }
    int path_sum = max(left_path_sum, right_path_sum) + node_list[i]->val;
    if (path_sum > 0) {
      sums[i] = path_sum;
    } else {
      sums[i] = 0;
    }

    // 比较
    if (sums[i] > result) {
      result = sums[i];
    }
  }

  return result;
}