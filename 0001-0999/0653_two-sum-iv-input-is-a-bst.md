[653.two-sum-iv-input-is-a-bst](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)  

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

**Example 1:**

  
**Input:** 
  
    5
  
   / \\
  
  3   6
  
 / \\   \\
  
2   4   7
  

  
Target = 9
  

  
**Output:** True
  

**Example 2:**

  
**Input:** 
  
    5
  
   / \\
  
  3   6
  
 / \\   \\
  
2   4   7
  

  
Target = 28
  

  
**Output:** False  



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
    unordered_map<int, int> m;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(m.count(k - root->val)) return true;
        m[root->val] = 1;
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
```
      