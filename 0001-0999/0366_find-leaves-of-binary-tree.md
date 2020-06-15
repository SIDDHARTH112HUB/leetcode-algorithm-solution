[366.find-leaves-of-binary-tree](https://leetcode.com/problems/find-leaves-of-binary-tree/)  

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

**Example:**

**Input:** \[1,2,3,4,5\] 1
         / \\
        2   3
       / \\     
      4   5    

**Output:** \[\[4,5,3\],\[2\],\[1\]\]

**Explanation:**

1\. Removing the leaves `[4,5,3]` would result in this tree:

          1
         / 
        2          

2\. Now removing the leaf `[2]` would result in this tree:

          1          

3\. Now removing the leaf `[1]` would result in the empty tree:

          \[\]  



**Solution:**  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        int idx = max(l, r) - 1;
        if(ans.size() <= idx) ans.push_back({});
        ans[idx].push_back(root->val);
        return max(l, r);
    }
};
```
      