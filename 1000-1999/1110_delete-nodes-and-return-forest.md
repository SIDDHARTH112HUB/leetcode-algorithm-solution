[1110.delete-nodes-and-return-forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)  

Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png)**

  
**Input:** root = \[1,2,3,4,5,6,7\], to\_delete = \[3,5\]
  
**Output:** \[\[1,2,null,4\],\[6\],\[7\]\]
  

**Constraints:**

*   The number of nodes in the given tree is at most `1000`.
*   Each node has a distinct value between `1` and `1000`.
*   `to_delete.length <= 1000`
*   `to_delete` contains distinct values between `1` and `1000`.  



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
    vector<TreeNode*> ans;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        if(s.count(root->val) == 0)
            ans.push_back(root);
        dfs(root, s);
        return ans;
    }
    
    void dfs(TreeNode* &root, unordered_set<int> &s) {
        if(!root) return;
        auto &l = root->left;
        auto &r = root->right;
        if(s.count(root->val)) {
            if(l && s.count(l->val) == 0)
                ans.push_back(l);
            if(r && s.count(r->val) == 0)
                ans.push_back(r);
            root = NULL;
        }
        dfs(l, s);
        dfs(r, s);
    }
};
```
      