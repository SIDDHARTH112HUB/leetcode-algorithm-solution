[1008.construct-binary-search-tree-from-preorder-traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)  

Return the root node of a binary **search** tree that matches the given `preorder` traversal.

_(Recall that a binary search tree is a binary tree where for every node, any descendant of `node.left` has a value `<` `node.val`, and any descendant of `node.right` has a value `>` `node.val`.  Also recall that a preorder traversal displays the value of the `node` first, then traverses `node.left`, then traverses `node.right`.)_

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

**Example 1:**

  
**Input:** \[8,5,1,7,10,12\]  
**Output:** \[8,5,10,1,7,null,12\]  
![](https://assets.leetcode.com/uploads/2019/03/06/1266.png)  

**Constraints:**

*   `1 <= preorder.length <= 100`
*   `1 <= preorder[i] <= 10^8`
*   The values of `preorder` are distinct.  



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
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int l = INT_MIN, int r = INT_MAX) {
        if(idx >= A.size()) return NULL;
        if(l > A[idx] || A[idx] > r) return NULL;
        int val = A[idx++];
        TreeNode *node = new TreeNode(val);
        if(idx < A.size())
            node->left = bstFromPreorder(A, l, val);
        if(idx < A.size())
            node->right = bstFromPreorder(A, val, r);
        return node;
    }
};
```
      