[156.binary-tree-upside-down](https://leetcode.com/problems/binary-tree-upside-down/)  

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

**Example:**

  
**Input:** \[1,2,3,4,5\]
  

  
    1
  
   / \\
  
  2   3
  
 / \\
  
4   5
  

  
**Output:** return the root of the binary tree \[4,5,2,#,#,3,1\]
  

  
   4
  
  / \\
  
 5   2
  
    / \\
  
   3   1  
  

**Clarification:**

Confused what `[4,5,2,#,#,3,1]` means? Read more below on how binary tree is serialized on OJ.

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

  
   1
  
  / \\
  
 2   3
  
    /
  
   4
  
    \\
  
     5
  

The above binary tree is serialized as `[1,2,3,#,#,4,#,#,5]`.  



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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) return root;
        auto l = root->left, r = root->right;
        auto res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};
```
      