[530.minimum-absolute-difference-in-bst](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)  

Given a binary search tree with non-negative values, find the minimum [absolute difference](https://en.wikipedia.org/wiki/Absolute_difference) between values of any two nodes.

**Example:**

  
**Input:**  
  
   1  
    \\  
     3  
    /  
   2  
  
**Output:**  
1  
  
**Explanation:**  
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).  

**Note:**

*   There are at least two nodes in this BST.
*   This question is the same as 783: [https://leetcode.com/problems/minimum-distance-between-bst-nodes/](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)  



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
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root, int mn = -10000000, int mx = 10000000) {
        if(!root) return 0;
        ans = min(ans, min(abs(root->val - mn), abs(root->val - mx)));
        getMinimumDifference(root->left, mn, root->val);
        getMinimumDifference(root->right, root->val, mx);
        return ans;
    }
};
```
      