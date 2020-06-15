[230.kth-smallest-element-in-a-bst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)  

Given a binary search tree, write a function `kthSmallest` to find the **k**th smallest element in it.

**Example 1:**

**Input:** root = \[3,1,4,null,2\], k = 1
   3
  / \\
 1   4
  \\
   2
**Output:** 1

**Example 2:**

**Input:** root = \[5,3,6,2,4,null,null,1\], k = 3
       5
      / \\
     3   6
    / \\
   2   4
  /
 1
**Output:** 3

**Follow up:**  
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

**Constraints:**

*   The number of elements of the BST is between `1` to `10^4`.
*   You may assume `k` is always valid, `1 ≤ k ≤ BST's total elements`.  



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
    int kthSmallest(TreeNode* root, int &k) {
        if( !root ) return -1;
        
        int val = kthSmallest(root->left, k );
        if( k <= 0 ) return val;
        k--;
        if( k == 0 )
            return root->val;
        return kthSmallest(root->right, k);
    }
};
```
      