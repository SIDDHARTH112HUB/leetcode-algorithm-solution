[563.binary-tree-tilt](https://leetcode.com/problems/binary-tree-tilt/)  

Given a binary tree, return the tilt of the **whole tree**.

The tilt of a **tree node** is defined as the **absolute difference** between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the **whole tree** is defined as the sum of all nodes' tilt.

**Example:**  

**Input:** 
         1
       /   \\
      2     3
**Output:** 1
**Explanation:** 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

**Note:**

1.  The sum of node values in any subtree won't exceed the range of 32-bit integer.
2.  All the tilt values won't exceed the range of 32-bit integer.  



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
    int helper(TreeNode* root, int &ans ){
        if( !root )
            return 0;
        int l = helper(root->left, ans);
        if( root->left )
            l += root->left->val;
        int r = helper(root->right, ans);
        if( root->right )
            r += root->right->val;
        ans += abs(l-r);
        return l+r;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
```
      