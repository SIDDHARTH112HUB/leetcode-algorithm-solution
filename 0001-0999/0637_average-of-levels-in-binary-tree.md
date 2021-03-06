[637.average-of-levels-in-binary-tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)  

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

**Example 1:**  

  
**Input:**
  
    3
  
   / \\
  
  9  20
  
    /  \\
  
   15   7
  
**Output:** \[3, 14.5, 11\]
  
**Explanation:**
  
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return \[3, 14.5, 11\].
  

**Note:**  

1.  The range of node's value is in the range of 32-bit signed integer.  



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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(q.size()) {
            int size = q.size();
            int cnt = size;
            long long sum = 0;
            while(size--  > 0) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(cnt)
                ans.push_back(sum*1.0/cnt);
        }
        return ans;
    }
};
```
      