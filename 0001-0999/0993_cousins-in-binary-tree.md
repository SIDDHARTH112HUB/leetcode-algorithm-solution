[993.cousins-in-binary-tree](https://leetcode.com/problems/cousins-in-binary-tree/)  

In a binary tree, the root node is at depth `0`, and children of each depth `k` node are at depth `k+1`.

Two nodes of a binary tree are _cousins_ if they have the same depth, but have **different parents**.

We are given the `root` of a binary tree with unique values, and the values `x` and `y` of two different nodes in the tree.

Return `true` if and only if the nodes corresponding to the values `x` and `y` are cousins.

**Example 1:  
![](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)**

  
**Input:** root = \[1,2,3,4\], x = 4, y = 3  
**Output:** false  

**Example 2:  
![](https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png)**

  
**Input:** root = \[1,2,3,null,4,null,5\], x = 5, y = 4  
**Output:** true  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png)**

  
**Input:** root = \[1,2,3,null,4\], x = 2, y = 3  
**Output:** false  

**Constraints:**

*   The number of nodes in the tree will be between `2` and `100`.
*   Each node has a unique integer value from `1` to `100`.  



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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> a = solve(NULL, root, x, 0);
        vector<int> b = solve(NULL, root, y, 0);
        if( a.size() == 0 || b.size() == 0 ) return false;
        if( a[0] != b[0] && a[1] ==b[1])
            return true;
        return false;
    }
    
    vector<int> solve(TreeNode* p,  TreeNode* root, int x, int h ){
        if( !root ) return {};
        if( root->val == x )
            return {p?p->val : 0, h};
        vector<int> ans ;
        if( root->left && (ans = solve(root, root->left, x, h+1)).size() > 0 )
            return ans;
        if( root->right && (ans = solve( root, root->right, x, h+1)).size() > 0 )
            return ans;
        return ans;
    }
};
```
      