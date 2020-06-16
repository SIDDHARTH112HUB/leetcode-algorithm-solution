[101.symmetric-tree](https://leetcode.com/problems/symmetric-tree/)  

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:

  
    1  
   / \\  
  2   2  
 / \\ / \\  
3  4 4  3  

But the following `[1,2,2,null,3,null,3]` is not:

  
    1  
   / \\  
  2   2  
   \\   \\  
   3    3  

**Follow up:** Solve it both recursively and iteratively.  



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
    bool isSymmetric(TreeNode* root) {
        if( !root ) return true;
        return sysmmetric(root->left, root->right);
    }
    
    bool sysmmetric(TreeNode* left, TreeNode* right){
        if( left && right ){
            if( left->val == right->val ){
                bool res = sysmmetric(left->left, right->right);
                if( !res )
                    return res;
                res = sysmmetric(left->right, right->left);
                return res;
            }
            return false;
        }
        return left == right;
    }
};
```
      