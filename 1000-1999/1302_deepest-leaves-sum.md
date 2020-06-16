[1302.deepest-leaves-sum](https://leetcode.com/problems/deepest-leaves-sum/)  

Given a binary tree, return the sum of values of its deepest leaves.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)**

  
**Input:** root = \[1,2,3,4,5,null,6,7,null,null,null,null,8\]
  
**Output:** 15
  

**Constraints:**

*   The number of nodes in the tree is between `1` and `10^4`.
*   The value of nodes is between `1` and `100`.  



**Solution:**  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
            map<int, int> m;
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;

        h(root, 0);
        return m.rbegin()->second;
    }
    void h(TreeNode* root, int d) {
        if(!root) return;
        m[d] += root->val;
        h(root->left, d+ 1);
        h(root->right, d + 1);
    }
};
```
      