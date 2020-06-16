[663.equal-tree-partition](https://leetcode.com/problems/equal-tree-partition/)  

Given a binary tree with `n` nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing **exactly** one edge on the original tree.

**Example 1:**  

  
**Input:**     
  
    5
  
   / \\
  
  10 10
  
    /  \\
  
   2   3
  

  
**Output:** True
  
**Explanation:** 
  
    5
  
   / 
  
  10
  
      
  
Sum: 15
  

  
   10
  
  /  \\
  
 2    3
  

  
Sum: 15
  

**Example 2:**  

  
**Input:**     
  
    1
  
   / \\
  
  2  10
  
    /  \\
  
   2   20
  

  
**Output:** False
  
**Explanation:** You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
  

**Note:**  

1.  The range of tree node value is in the range of \[-100000, 100000\].
2.  1 <= n <= 10000  



**Solution:**  

```cpp

class Solution {
public:
    int sum = 0;
    bool res = false;
    TreeNode* root;
    bool checkEqualTree(TreeNode* root) {
        this->root = root;
        sumTree(root);
        if(sum % 2) return false;
        findPart(root);
        return res;
    }

    void sumTree(TreeNode *root) {
        if(!root) return;
        sum += root->val;
        sumTree(root->left);
        sumTree(root->right);
    }
    
    int findPart(TreeNode *root) {
        if(!root) return 0;
        int l = findPart(root->left);
        int r = findPart(root->right);
        int partSum = l + r + root->val;
        if(root->left && sum - l == l) res = true;
        else if(root->right && sum - r == r) res = true;
        else if(sum - partSum == partSum && this->root != root) res = true;
        return partSum;
    }
};
```
      