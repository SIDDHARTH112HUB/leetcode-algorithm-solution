[1382.balance-a-binary-search-tree](https://leetcode.com/problems/balance-a-binary-search-tree/)  

Given a binary search tree, return a **balanced** binary search tree with the same node values.

A binary search tree is _balanced_ if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/08/22/1515_ex1.png)![](https://assets.leetcode.com/uploads/2019/08/22/1515_ex1_out.png)**

  
**Input:** root = \[1,null,2,null,3,null,4,null,null\]
  
**Output:** \[2,1,3,null,null,null,4\]
  
**Explanation:** This is not the only correct answer, \[3,1,4,null,2,null,null\] is also correct.
  

**Constraints:**

*   The number of nodes in the tree is between `1` and `10^4`.
*   The tree nodes will have distinct values between `1` and `10^5`.  



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
    vector<int> arr;
    TreeNode* balanceBST(TreeNode* root) {
        d(root);
        sort(arr.begin(), arr.end());
        return h(0, arr.size()-1);
    }
    
    void d(TreeNode* root) {
        if(!root) return;
        arr.push_back(root->val);
        d(root->left);
        d(root->right);
    }
    TreeNode* h(int l, int r) {
        if(l > r) return NULL;
        if(l == r) return new TreeNode(arr[l]);
        int mid = (l + r) / 2;
        auto node = new TreeNode(arr[mid]);
        node->left = h( l, mid - 1);
        node->right = h( mid + 1, r);
        return node;
    }
};
```
      