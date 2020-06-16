[1123.lowest-common-ancestor-of-deepest-leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)  

Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

*   The node of a binary tree is a _leaf_ if and only if it has no children
*   The _depth_ of the root of the tree is 0, and if the depth of a node is `d`, the depth of each of its children is `d+1`.
*   The _lowest common ancestor_ of a set `S` of nodes is the node `A` with the largest depth such that every node in S is in the subtree with root `A`.

**Example 1:**

  
**Input:** root = \[1,2,3\]  
**Output:** \[1,2,3\]  
**Explanation:**   
The deepest leaves are the nodes with values 2 and 3.  
The lowest common ancestor of these leaves is the node with value 1.  
The answer returned is a TreeNode object (not an array) with serialization "\[1,2,3\]".  

**Example 2:**

  
**Input:** root = \[1,2,3,4\]  
**Output:** \[4\]  

**Example 3:**

  
**Input:** root = \[1,2,3,4,5\]  
**Output:** \[2,4,5\]  

**Constraints:**

*   The given tree will have between 1 and 1000 nodes.
*   Each node of the tree will have a distinct value between 1 and 1000.  



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
    vector<TreeNode*> deepest;
    TreeNode* ans;
    int deep = 0;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    int dfs(TreeNode *root, int d) {
        if(!root) return 0;
        int l = 1, r =1;
        if(root->left)
            l += dfs(root->left, d+1);
        if(root->right)
            r += dfs(root->right, d+1);
        if(l == r && d + l >= deep){
            ans = root;
            deep = d + l;
        }
        return max(l, r);
    }
};
```
      