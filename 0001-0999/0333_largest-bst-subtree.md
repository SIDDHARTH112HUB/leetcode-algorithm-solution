[333.largest-bst-subtree](https://leetcode.com/problems/largest-bst-subtree/)  

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

**Note:**  
A subtree must include all of its descendants.

**Example:**

**Input:** \[10,5,15,1,8,null,7\]

   10 
   / \\ 
 5  15 
 / \\   \\ 
1   8   7

**Output:** 3
**Explanation:** The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.

**Follow up:**  
Can you figure out ways to solve it with O(n) time complexity?  



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
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root) {
        if(!root) return {INT_MAX, INT_MIN, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(l[1] < root->val && r[0] > root->val) {
            ans = max(ans, l[2] + r[2] + 1);
            return { min(l[0], root->val), max(r[1],root->val), l[2] + r[2] + 1 };
        }else
            return {INT_MIN, INT_MAX, 0};
    }
};
```
      