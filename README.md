### <font color=green>1.算法</font>
#### <font color=orange>链表</font>
```
最重要是确定需要哪些临时节点：
cur:  当前遍历节点
next: 下一个遍历节点
head: 头节点
tail: 尾节点

```
```
- 第206题，　　反转链表
- 第023题，　　合并 K 个链表
- 第025题，　　K 个一组反转链表
- 第109题，　　有序链表转换二叉搜索树

```

#### <font color=orange>搜索树</font>
```
- 第101题，　　对称二叉树
- 第114题，　　二叉树展开为链表
- 第99题，　　 恢复二叉树搜索树
- 第098题，　　验证二叉搜索树
- 第102题，　　二叉树的层序遍历
- 第124题，　　二叉树中的最大路径和(***)

```

#### <font color=orange>动态规划</font>
```
一维,保证 dp[i-1] ==> dp[i]
二维,保证 dp[i+1][j-1] ==> dp[i][j]
```
```
- 第096题，  不同的二叉搜索树（dp[i]）。

- 第005题，  最长回文字符串（dp[i][j]）。
- 第032题，  最长有效括号　（dp[i][j]）。
- 第072题，  编辑距离。    (dp[i][j])
- 第115题，  不同子序列。　（dp[i][j]）(***)。
```

#### <font color=orange>回溯</font>
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
```
```
第37题，解数独。
第39题，数组总和。
第40题，数组总和2（重点在于去重，也是一种剪枝）。
第46题，全排序。
第51题，n 皇后。
第78题，子集(***)。
第79题，单词搜索。
```

#### #### <font color=orange>其他</font>
```
快排:               3_algorithm / 01_quick_sort.cc
归并排序：           3_algorithm / 02_merge_sort.cc

广度优先（BFS）:
深度优先（DFS）:
递归：　　　　　　　　 第44题， 通配符匹配。
二差搜索:
滑动窗口:            无重复字符的最长子串长度

```

### <font color=green>2.数据结构</font>
#### <font color=orange>队列与栈</font>
```
1_stl / 4_1_queue.cc
1_stl / 4_3_stack.cc

```

#### <font color=orange>树与堆</font>
```
2_data_struct / 2_1_binary_tree.cc
2_data_struct / 3_1_heap.cc
```

#### <font color=orange>图</font>
```
2_data_struct / 4_1_graph.cc
```