[337.house-robber-iii](https://leetcode.com/problems/house-robber-iii/)  

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

**Example 1:**

  
**Input:** \[3,2,3,null,3,null,1\]
  

  
     3
  
    / \\
  
   2   3
  
    \\   \\ 
  
     3   1 
  
**Output:** 7 
  
**Explanation:** Maximum amount of money the thief can rob = 3 + 3 + 1 = **7**.

**Example 2:**

  
**Input:** \[3,4,5,1,3,null,1\]
  

  
     3
  
    / \\
  
   4   5
  
  / \\   \\ 
  
 1   3   1
  

  
**Output:** 9
  
**Explanation:** Maximum amount of money the thief can rob = 4 + 5 = **9**.  



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
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if( m.count(root) ) return m[root];
        m[root] = root ? max(root->val + 
             (root->left ?  (rob(root->left->left) + rob(root->left->right) ) : 0 ) +
             (root->right? (rob(root->right->left) + rob(root->right->right) ) :0),
             rob(root->left) + rob(root->right)) : 0;
        return m[root];
    }
};


```
      