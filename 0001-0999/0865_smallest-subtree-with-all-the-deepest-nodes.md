[865.smallest-subtree-with-all-the-deepest-nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)  

Given a binary tree rooted at `root`, the _depth_ of each node is the shortest distance to the root.

A node is _deepest_ if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

**Example 1:**

**Input:** \[3,5,1,6,2,0,8,null,null,7,4\]
**Output:** \[2,7,4\]
**Explanation:** 
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png)

We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "\[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4\]" is a serialization of the given tree.
The output "\[2, 7, 4\]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.

**Note:**

*   The number of nodes in the tree will be between 1 and 500.
*   The values of each node are unique.  



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
    TreeNode* ans = NULL;
    int depth = 0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    int dfs(TreeNode* root, int d) {
        if(!root) return d;
        int l = dfs(root->left, d + 1);
        int r = dfs(root->right, d + 1);
        if(l >= depth && r >= depth) {
            depth = max(l, r);
            ans = root;
        }
        return max(l, r);
    }
};
```
      