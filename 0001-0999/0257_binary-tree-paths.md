[257.binary-tree-paths](https://leetcode.com/problems/binary-tree-paths/)  

Given a binary tree, return all root-to-leaf paths.

**Note:** A leaf is a node with no children.

**Example:**

**Input:**

   1
 /   \\
2     3
 \\
  5

**Output:** \["1->2->5", "1->3"\]

**Explanation:** All root-to-leaf paths are: 1->2->5, 1->3  



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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        dfs(root, str);
        return ans;
    }
    
    void dfs(TreeNode* root, string &str) {
        if(!root) return;
        
        string valstr = to_string(root->val);
        str += valstr;
        if(!root->left && !root->right) {
            ans.push_back(str);
            str = str.substr(0, str.size() - valstr.size());
            return;
        }
        if(root->left) {
            str += "->";
            dfs(root->left, str);
            str = str.substr(0, str.size()-2);
        }
        if(root->right) {
            str += "->";
            dfs(root->right, str);
            str = str.substr(0, str.size()-2);
        }
        str = str.substr(0, str.size() - valstr.size());
    }
};
```
      