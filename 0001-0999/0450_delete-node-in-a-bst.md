[450.delete-node-in-a-bst](https://leetcode.com/problems/delete-node-in-a-bst/)  

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1.  Search for a node to remove.
2.  If the node is found, delete the node.

**Note:** Time complexity should be O(height of tree).

**Example:**

  
root = \[5,3,6,2,4,null,7\]
  
key = 3
  

  
    5
  
   / \\
  
  3   6
  
 / \\   \\
  
2   4   7
  

  
Given key to delete is 3. So we find the node with value 3 and delete it.
  

  
One valid answer is \[5,4,6,2,null,null,7\], shown in the following BST.
  

  
    5
  
   / \\
  
  4   6
  
 /     \\
  
2       7
  

  
Another valid answer is \[5,2,6,null,4,null,7\].
  

  
    5
  
   / \\
  
  2   6
  
   \\   \\
  
    4   7  



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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( !root )
            return NULL;
        if( root->val > key )
            root->left = deleteNode(root->left, key);
        else if( root->val < key)
            root->right = deleteNode(root->right, key);
        else{
            if( !root->left || !root->right)
                root = root->left ? root->left : root->right;
            else{
                auto cur = root->right;
                while( cur->left ) cur = cur->left;
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};
```
      