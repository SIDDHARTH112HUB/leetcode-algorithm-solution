[199.binary-tree-right-side-view](https://leetcode.com/problems/binary-tree-right-side-view/)  

Given a binary tree, imagine yourself standing on the _right_ side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

  
**Input:** \[1,2,3,null,5,null,4\]
  
**Output:** \[1, 3, 4\]
  
**Explanation:** 
  
   1            <---
  
 /   \\
  
2     3         <---
  
 \\     \\
  
  5     4       <---  



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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> pq;
        pq.push(root);
        vector<int> ans;
        while( pq.size() ){
            int size = pq.size();
            TreeNode* node = NULL;
            ans.push_back(pq.front()->val);
            while( size-- > 0 ){
                node = pq.front();
                pq.pop();
                if(node->right)
                    pq.push(node->right);
                if( node->left )
                    pq.push(node->left);
            }
        }
        return ans;
    }
};
```
      