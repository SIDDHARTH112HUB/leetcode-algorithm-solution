[404.sum-of-left-leaves](https://leetcode.com/problems/sum-of-left-leaves/)  

Find the sum of all left leaves in a given binary tree.

**Example:**

    3
   / \\
  9  20
    /  \\
   15   7

There are two left leaves in the binary tree, with values **9** and **15** respectively. Return **24**.  



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
    int sumOfLeftLeaves(TreeNode* root, int deep= 0) {
        if( !root ) return 0;
        int ans = 0;
        ans += sumOfLeftLeaves(root->left, deep+1);
        ans += sumOfLeftLeaves(root->right, 0);
        if( !root->left && !root->right && deep > 0)
            ans += root->val;
        return ans;
    }
};
```
      