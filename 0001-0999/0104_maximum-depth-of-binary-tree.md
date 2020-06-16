[104.maximum-depth-of-binary-tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)  

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Note:** A leaf is a node with no children.

**Example:**

Given binary tree `[3,9,20,null,null,15,7]`,

  
    3
  
   / \\
  
  9  20
  
    /  \\
  
   15   7

return its depth = 3.  



**Solution:**  

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getHeight( TreeNode* node, int deep ){
        int hl=0, hr=0;
        if( node->left == NULL && node->right == NULL )
            return deep;
        if(node->left != NULL)
            hl = getHeight(node->left, deep+1);
        if(node->right != NULL)
            hr = getHeight(node->right, deep+1);
        return hl>hr?hl:hr;
        
    }
    int maxDepth(TreeNode *root) {
        if( root == NULL )return 0;
        return getHeight(root, 1);
    }
};
```
      