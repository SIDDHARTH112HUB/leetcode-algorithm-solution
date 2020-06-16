[958.check-completeness-of-a-binary-tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)  

Given a binary tree, determine if it is a _complete binary tree_.

**Definition of a complete binary tree from [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees):**  
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)**

  
**Input:** \[1,2,3,4,5,6\]
  
**Output:** true
  
**Explanation:** Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png)**

  
**Input:** \[1,2,3,4,5,null,7\]
  
**Output:** false
  
**Explanation:** The node with value 7 isn't as far left as possible. 

**Note:**

1.  The tree will have between 1 and 100 nodes.  



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
    bool isCompleteTree1(TreeNode* root) {
        if( !root ) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeaveLevel = false;
        while( q.size() ){
            int size = q.size();
            while( size-- > 0 ){
                auto node = q.front();
                q.pop();
                if( isLeaveLevel && (node->left || node->right ) )
                    return false;
                if( !node->left && node->right )
                    return false;
                if( node->left )
                    q.push(node->left);
                if( node->right)
                    q.push(node->right);
                if( !node->left || !node->right )
                    isLeaveLevel = true;
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        h(root);
        return res;
    }
    bool res = true;
    int h(TreeNode* root) {
        if(!root) return 0;
        int l = h(root->left) + 1;
        int r = h(root->right) + 1;
        if(r > l || l - 1 >r) {
            res = false;
        }
        return max(l, r);
    }
};
```
      