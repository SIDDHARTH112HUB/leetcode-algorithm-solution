[549.binary-tree-longest-consecutive-sequence-ii](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)  

Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, \[1,2,3,4\] and \[4,3,2,1\] are both considered valid, but the path \[1,2,4,3\] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

**Example 1:**

  
**Input:**
  
        1
  
       / \\
  
      2   3
  
**Output:** 2
  
**Explanation:** The longest consecutive path is \[1, 2\] or \[2, 1\].
  

**Example 2:**

  
**Input:**
  
        2
  
       / \\
  
      1   3
  
**Output:** 3
  
**Explanation:** The longest consecutive path is \[1, 2, 3\] or \[3, 2, 1\].
  

**Note:** All the values of tree nodes are in the range of \[-1e7, 1e7\].  



**Solution:**  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        dfs(root, root);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root, TreeNode* parent) {
        if(!root) return {0, 0};
        auto l = dfs(root->left, root);
        auto r = dfs(root->right, root);
        res = max(res, l.first + r.second + 1);
        res = max(res, l.second + r.first + 1);
        int inc = 0, dec = 0;
        if (root->val == parent->val + 1) {
            dec = max(l.second, r.second) + 1;
        } else if (root->val + 1 == parent->val) {
            inc = max(l.first, r.first) + 1;
        }
        return {inc, dec};
    }
};
```
      