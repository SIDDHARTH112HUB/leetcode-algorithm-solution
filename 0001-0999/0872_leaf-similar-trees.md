[872.leaf-similar-trees](https://leetcode.com/problems/leaf-similar-trees/)  

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a _leaf value sequence._

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png)

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered _leaf-similar_ if their leaf value sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.

**Constraints:**

*   Both of the given trees will have between `1` and `200` nodes.
*   Both of the given trees will have values between `0` and `200`  



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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1, s2;
        dfs(root1, s1);
        dfs(root2, s2);
        if( s1.size() != s2.size() ) return false;
        for( int i = 0; i<s1.size(); i++){
            if( s1[i] != s2[i])
                return false;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int> &s){
        if( !root )
            return;
        if( !root->left && !root->right){
            s.push_back(root->val);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
};
```
      