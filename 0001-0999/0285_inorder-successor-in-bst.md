[285.inorder-successor-in-bst](https://leetcode.com/problems/inorder-successor-in-bst/)  

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node `p` is the node with the smallest key greater than `p.val`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG)

  
**Input:** root = \[2,1,3\], p = 1
  
**Output:** 2
  
**Explanation:** 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG)

  
**Input:** root = \[5,3,6,2,4,null,null,1\], p = 6
  
**Output:** null
  
**Explanation:** There is no in-order successor of the current node, so the answer is `null`.
  

**Note:**

1.  If the given node has no in-order successor in the tree, return `null`.
2.  It's guaranteed that the values of the tree are unique.  



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
    bool find = false;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        auto l = inorderSuccessor(root->left, p);
        if(l) return l;
        if(find == true) return root;
        find = root == p;
        return inorderSuccessor(root->right, p);
    }
    
};
```
      