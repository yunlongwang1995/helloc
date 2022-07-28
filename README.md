### <font color=green>数据结构</font>
#### 队列（优先）
1_stl / 4_1_queue.cc
#### 栈
1_stl / 4_3_stack.cc
#### 二叉树
2_data_struct / 2_1_binary_tree.cc
#### 堆
2_data_struct / 3_1_heap.cc
#### 图
2_data_struct / 4_1_graph.cc

### <font color=green>算法</font>
#### 快排
3_algorithm / 01_quick_sort.cc
#### 合并排序
3_algorithm / 02_merge_sort.cc

### <font color=green>Leetcode</font>
#### 动态规划
```
// 一维,保证 dp[i-1] ==> dp[i]
// 二维,保证 dp[i+1][j-1] ==> dp[i][j]

- 第5题，  最长回文字符串（dp[i][j]）。
- 第32题， 最长有效括号　（dp[i]）。
- 第72题， 编辑距离。    (dp[i][j])
- 第115题，不同子序列。　（也可以转换一下，用回溯）
```
#### 递归
```
- 第44题， 通配符匹配。　（遇到递归时，需要多考虑一下）
```
#### 回溯
```
void dfs(params) {
    // 基准情况
    
    // 循环每一种情况
    for (auto item: all) {
        // 剪枝（要提前做）
        
        // 递归
        dfs(params1);
    }
}

第37题，解数独。
第39题，数组总和。
第40题，数组总和2（重点在于去重，也是一种剪枝）。
第46题，全排序。
第51题，n 皇后。
第78题，子集。
第79题，单词搜索。
```