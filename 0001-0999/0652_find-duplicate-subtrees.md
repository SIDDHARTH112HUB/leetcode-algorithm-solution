[652.find-duplicate-subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)  

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are duplicate if they have the same structure with same node values.

**Example 1:**

  
        1
  
       / \\
  
      2   3
  
     /   / \\
  
    4   2   4
  
       /
  
      4
  

The following are two duplicate subtrees:

  
      2
  
     /
  
    4
  

and

  
    4
  

Therefore, you need to return above trees' root in the form of a list.  



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
    unordered_map<string, int> m;
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        f(root);
        return ans;
    }
    
    string f(TreeNode* root) {
        if(!root) return "#";
        string res = to_string(root->val) + "," + f(root->left) + "," + f(root->right);
        if(m[res]++ == 1) ans.push_back(root);
        return res;
    }
};
```
      