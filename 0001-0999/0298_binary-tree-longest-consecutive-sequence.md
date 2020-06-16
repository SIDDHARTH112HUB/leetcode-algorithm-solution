[298.binary-tree-longest-consecutive-sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)  

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

**Example 1:**

  
**Input:**
  

  
   1
  
    \\
  
     3
  
    / \\
  
   2   4
  
        \\
  
         5
  

  
**Output:** `3`
  

  
**Explanation:** Longest consecutive sequence path is `3-4-5`, so return `3`.

**Example 2:**

  
**Input:
  

  
**   2
  
    \\
  
     3
  
    / 
  
   2    
  
  / 
  
 1
  

  
**Output: 2 
  

  
Explanation:** Longest consecutive sequence path is `2-3`, not `3-2-1`, so return `2`.  



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
    int ans = 0;
    int longestConsecutive(TreeNode* root) {
        dfs(root, -1000000);
        return ans;
    }
    
    pair<int, int> dfs(TreeNode* root, int p) {
        if(!root) return {1, 1};
        auto l = dfs(root->left, root->val);
        auto r = dfs(root->right, root->val);
        pair<int, int> res = {1, 1};
        if(p - root->val == 1) {
            res = {max(l.first, r.first) + 1,  1};
        }else if(root->val - p == 1) {
            res = {1, max(l.second, r.second) + 1};
        }
        ans = max(ans, res.second);
        return res;
    }
};
```
      