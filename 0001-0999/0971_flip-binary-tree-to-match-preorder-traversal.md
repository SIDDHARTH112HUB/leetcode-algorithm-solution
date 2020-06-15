[971.flip-binary-tree-to-match-preorder-traversal](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)  

Given a binary tree with `N` nodes, each node has a different value from `{1, ..., N}`.

A node in this binary tree can be _flipped_ by swapping the left child and the right child of that node.

Consider the sequence of `N` values reported by a preorder traversal starting from the root.  Call such a sequence of `N` values the _voyage_ of the tree.

(Recall that a _preorder traversal_ of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the **least number** of nodes in the tree so that the voyage of the tree matches the `voyage` we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list `[-1]`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/01/02/1219-01.png)**

**Input:** root = \[1,2\], voyage = \[2,1\]
**Output:** \[-1\]

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/01/02/1219-02.png)**

**Input:** root = \[1,2,3\], voyage = \[1,3,2\]
**Output:** \[1\]

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/01/02/1219-02.png)**

**Input:** root = \[1,2,3\], voyage = \[1,2,3\]
**Output:** \[\]

**Note:**

1.  `1 <= N <= 100`  



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
    vector<int> ans;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        if( !dfs(root, voyage, idx))
            return {-1};
        return ans;
    }
    
    bool dfs( TreeNode* root, vector<int>& voyage, int &idx){
        if( !root ) return true;
        if( root->val != voyage[idx]) return false;
        if( root->left && root->left->val != voyage[idx+1]){
            if( !root->right || root->right->val != voyage[idx+1] )
                return false;
            ans.push_back(root->val);
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            
        }
        ++idx;
        if( !dfs(root->left, voyage, idx) )
            return false;
        if( !dfs(root->right, voyage, idx) )
            return false;
        return true;
    }
};
```
      