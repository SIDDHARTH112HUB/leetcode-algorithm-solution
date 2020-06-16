[1120.maximum-average-subtree](https://leetcode.com/problems/maximum-average-subtree/)  

Given the `root` of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/04/09/1308_example_1.png)

  
**Input:** \[5,6,1\]  
**Output:** 6.00000  
**Explanation: **  
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.  
For the node with value = 6 we have an average of 6 / 1 = 6.  
For the node with value = 1 we have an average of 1 / 1 = 1.  
So the answer is 6 which is the maximum.  

**Note:**

1.  The number of nodes in the tree is between `1` and `5000`.
2.  Each node will have a value between `0` and `100000`.
3.  Answers will be accepted as correct if they are within `10^-5` of the correct answer.  



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
    double ans = 0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    pair<int, int> dfs(TreeNode *root){
        if(!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int total = root->val + l.first + r.first;
        int count = 1 + l.second + r.second;
        ans = max(ans, double(total*1.0/ count));
        return {total, count};
    }
};
```
      