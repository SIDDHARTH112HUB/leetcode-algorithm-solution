[513.find-bottom-left-tree-value](https://leetcode.com/problems/find-bottom-left-tree-value/)  

Given a binary tree, find the leftmost value in the last row of the tree.

**Example 1:**  

Input:

    2
   / \\
  1   3

Output:
1

**Example 2:**  

Input:

        1
       / \\
      2   3
     /   / \\
    4   5   6
       /
      7

Output:
7

**Note:** You may assume the tree (i.e., the given root node) is not **NULL**.  



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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(q.size()){
            int size = q.size();
            if(size)
                ans = q.front()->val;
            while(size-- > 0) {
                auto node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
```
      