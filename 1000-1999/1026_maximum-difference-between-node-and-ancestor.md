[1026.maximum-difference-between-node-and-ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)  

Given the `root` of a binary tree, find the maximum value `V` for which there exists **different** nodes `A` and `B` where `V = |A.val - B.val|` and `A` is an ancestor of `B`.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/09/09/2whqcep.jpg)

  
**Input:** \[8,3,10,1,6,null,14,null,null,4,7,13\]  
**Output:** 7  
**Explanation: **  
We have various ancestor-node differences, some of which are given below :  
|8 - 3| = 5  
|3 - 7| = 4  
|8 - 1| = 7  
|10 - 13| = 3  
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.  

**Note:**

1.  The number of nodes in the tree is between `2` and `5000`.
2.  Each node will have value between `0` and `100000`.  



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
    int ans = INT_MIN;
    int maxAncestorDiff(TreeNode* root, int mn = INT_MAX, int mx = INT_MIN) {
        if(!root) return INT_MIN;
        if(mn != INT_MAX) {
            int res = max(abs(root->val - mn), abs(root->val - mx));
            ans = max(ans, res);
        }
        maxAncestorDiff(root->left, min(mn, root->val), max(mx, root->val));
        maxAncestorDiff(root->right, min(mn, root->val), max(mx, root->val));
        return ans;
    }
};
```
      