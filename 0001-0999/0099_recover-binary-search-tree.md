[99.recover-binary-search-tree](https://leetcode.com/problems/recover-binary-search-tree/)  

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

**Example 1:**

**Input:** \[1,3,null,null,2\]

   1
  /
 3
  \\
   2

**Output:** \[3,1,null,null,2\]

   3
  /
 1
  \\
   2

**Example 2:**

**Input:** \[3,1,4,null,null,2\]

  3
 / \\
1   4
   /
  2

**Output:** \[2,1,4,null,null,3\]

  2
 / \\
1   4
   /
  3

**Follow up:**

*   A solution using O(_n_) space is pretty straight forward.
*   Could you devise a constant space solution?  



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
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        int idx = -1;
        dfs(root, arr, idx);
        sort(arr.begin(), arr.end());
        idx = 0;
        dfs(root, arr, idx);
    }
    void dfs(TreeNode* root, vector<int> &arr, int &idx){
        if( !root )return;
        if( root->left )
            dfs(root->left, arr, idx);
        if( idx == -1 )
            arr.push_back(root->val);
        else{
            root->val = arr[idx++];
        }
        if( root->right )
            dfs(root->right, arr, idx);
    }
};
```
      