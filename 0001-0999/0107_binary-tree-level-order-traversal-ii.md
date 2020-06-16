[107.binary-tree-level-order-traversal-ii](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)  

Given a binary tree, return the _bottom-up level order_ traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:  
Given binary tree `[3,9,20,null,null,15,7]`,  

  
    3
  
   / \\
  
  9  20
  
    /  \\
  
   15   7
  

return its bottom-up level order traversal as:  

  
\[
  
  \[15,7\],
  
  \[9,20\],
  
  \[3\]
  
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        vector< vector< int > > data;
        if( root == NULL ) return data;
        vector< TreeNode* > nodes;
        nodes.push_back( root );
        int idx = 0, size = nodes.size();
        
        while( idx < size )
        {
            vector< int > row;
            for( ; idx<size; idx++)
            {
                TreeNode* node = nodes[idx];
                row.push_back( node->val);
                if( node->left != NULL ) nodes.push_back( node->left);
                if( node->right != NULL ) nodes.push_back( node->right);
            }
            data.push_back( row );
            //row.clear();
            size = nodes.size();
            
        }
        std::reverse( data.begin(), data.end());
        return data;
    }
};
```
      