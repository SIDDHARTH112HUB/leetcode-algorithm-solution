[501.find-mode-in-binary-search-tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/)  

Given a binary search tree (BST) with duplicates, find all the [mode(s)](https://en.wikipedia.org/wiki/Mode_(statistics)) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

*   The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
*   The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
*   Both the left and right subtrees must also be binary search trees.

For example:  
Given BST `[1,null,2,2]`,

   1
    \\
     2
    /
   2

return `[2]`.

**Note:** If a tree has more than one mode, you can return them in any order.

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).  



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
    map<int, int> data;
    int max_num = 0;
    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans;
        for(auto &it:data){
            if( it.second == max_num )
                ans.push_back(it.first);
        }
        return ans;
    }
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        solve(root->right);
        data[root->val]++;
        if( data[root->val] > max_num )
            max_num = data[root->val];
    }
};
```
      