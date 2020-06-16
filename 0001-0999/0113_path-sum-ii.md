[113.path-sum-ii](https://leetcode.com/problems/path-sum-ii/)  

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

  
      **5**
  
     **/ \\**
  
    **4   8**
  
   **/**   / **\\**
  
  **11**  13  **4**
  
 /  **\\**    **/** \\
  
7    **2**  **5**   1
  

Return:

  
\[
  
   \[5,4,11,2\],
  
   \[5,8,4,5\]
  
\]  



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
    vector< vector<int> > ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if( !root ) return ans;
        vector<int> item;
        dfs(root, sum, item);
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<int> &item){
        if( sum == root->val && root->left == nullptr && root->right == nullptr){
            item.push_back(root->val);
            ans.push_back(item);
            item.pop_back();
            return;
        }
        if( !root )
            return;
        item.push_back(root->val);
        if( root->left )
            dfs(root->left, sum-root->val, item);
        if( root->right)
            dfs(root->right, sum-root->val, item);
        item.pop_back();
    }
};
```
      