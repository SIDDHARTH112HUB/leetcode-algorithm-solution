[536.construct-binary-tree-from-string](https://leetcode.com/problems/construct-binary-tree-from-string/)  

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the **left** child node of the parent first if it exists.

**Example:**  

**Input:** "4(2(3)(1))(6(5))"
**Output:** return the tree root node representing the following tree:

       4
     /   \\
    2     6
   / \\   / 
  3   1 5   

**Note:**  

1.  There will only be `'('`, `')'`, `'-'` and `'0'` ~ `'9'` in the input string.
2.  An empty tree is represented by `""` instead of `"()"`.  



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
    TreeNode* str2tree(string s) {
        if(s == "") return NULL;
        int idx = 0;
        return dfs(s, idx);
    }
    
    TreeNode* dfs(string &s, int &idx) {
        if(idx >= s.size()) return NULL;
        int sign = 1;
        if(s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        int sum = 0;
        while(s[idx] <= '9' && s[idx] >= '0') {
            sum = sum * 10 + s[idx] - '0';
            ++idx;
        }
        TreeNode* node = new TreeNode(sum * sign);
        if(idx >= s.size()) return node;
        if(s[idx] == ')') {
            ++idx;
            return node;
        }
        ++idx;
        node->left = dfs(s, idx);
        if(idx >= s.size()) return node;
        if(idx < s.size() && s[idx] == ')') {
            ++idx;
            return node;
        }
        ++idx;
        node->right = dfs(s, idx);
        ++idx;
        return node;
    }
};
```
      