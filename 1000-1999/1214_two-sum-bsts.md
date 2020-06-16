[1214.two-sum-bsts](https://leetcode.com/problems/two-sum-bsts/)  

Given two binary search trees, return `True` if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer `target`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/05/31/1368_1_a2.png)![](https://assets.leetcode.com/uploads/2019/05/31/1368_1_b.png)**

  
**Input:** root1 = \[2,1,4\], root2 = \[1,0,3\], target = 5  
**Output:** true  
**Explanation:** 2 and 3 sum up to 5.  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/05/31/1368_2_a.png)![](https://assets.leetcode.com/uploads/2019/05/31/1368_2_b.png)**

  
**Input:** root1 = \[0,-10,10\], root2 = \[5,1,7,0,2\], target = 18  
**Output:** false  

**Constraints:**

*   Each tree has at most `5000` nodes.
*   `-10^9 <= target, node.val <= 10^9`  



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
    unordered_set<int> m;
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2) return false;
        helper(root1);
        return helper2(root2, target);
    }
    void helper(TreeNode* root) {
        if(!root) return;
        m.insert(root->val);
        helper(root->left);
        helper(root->right);
    }
    bool helper2(TreeNode* root, int target) {
        if(!root) return false;
        if(m.count(target - root->val)) return true;
        if(helper2(root->left, target)) return true;
        if(helper2(root->right, target)) return true;
        return false;
    }
};
```
      