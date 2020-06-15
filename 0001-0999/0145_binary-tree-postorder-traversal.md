[145.binary-tree-postorder-traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)  

Given a binary tree, return the _postorder_ traversal of its nodes' values.

**Example:**

**Input:** `[1,null,2,3]`
   1
    \\
     2
    /
   3

**Output:** `[3,2,1]`

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
    vector<int> ans;
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk1;
        TreeNode* p = root;
        TreeNode* q = NULL;
        while(stk1.size() || p){
            if( p ){
                stk1.push(p);
                p = p->left;
            }else{
                q= NULL;
                post:
                if( stk1.empty() )
                    break;
                p = stk1.top();
                if( p->right == q ){
                    ans.push_back(p->val);
                    stk1.pop();
                    q = p;
                    goto post;
                }else{
                    p = p->right;
                }
            }
        }
        return ans;
    }
};
```
      