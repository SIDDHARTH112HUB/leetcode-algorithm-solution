[144.binary-tree-preorder-traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)  

Given a binary tree, return the _preorder_ traversal of its nodes' values.

**Example:**

  
**Input:** `[1,null,2,3]`
  
   1
  
    \\
  
     2
  
    /
  
   3
  

  
**Output:** `[1,2,3]`
  

**Follow up:** Recursive solution is trivial, could you do it iteratively?  



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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        if( root )
            stk.push(root);
        while( stk.size()){
            p = stk.top();
            stk.pop();
            ans.push_back(p->val);
            if( p->right )
                stk.push(p->right);
            if( p->left )
                stk.push(p->left);
        }
        return ans;
    }
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while( stk.size() || p){
            if( p ){
                ans.push_back(p->val);
                stk.push(p);
                p = p->left;
            }else{
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
```
      