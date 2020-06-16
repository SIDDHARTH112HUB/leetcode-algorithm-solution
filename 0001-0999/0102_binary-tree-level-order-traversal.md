[102.binary-tree-level-order-traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)  

Given a binary tree, return the _level order_ traversal of its nodes' values. (ie, from left to right, level by level).

For example:  
Given binary tree `[3,9,20,null,null,15,7]`,  

  
    3
  
   / \\
  
  9  20
  
    /  \\
  
   15   7
  

return its level order traversal as:  

  
\[
  
  \[3\],
  
  \[9,20\],
  
  \[15,7\]
  
\]  



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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<TreeNode*> t;
        vector<vector<int> > res;
        if( root == NULL ) return res;
        t.push_back(root);
        int i = 0;
        vector<int > tmp;
        while( t.size() > i ){
            int size = t.size();
            res.push_back( tmp );
            vector<int>& d = res[res.size()-1];
            for( ; i < size; i++)
            {
                d.push_back( t[i]->val );
                if( t[i]->left !=NULL)
                    t.push_back( t[i]->left );
                if( t[i]->right != NULL )
                    t.push_back( t[i]->right);
            }
        }
        return res;
    }
};
```
      