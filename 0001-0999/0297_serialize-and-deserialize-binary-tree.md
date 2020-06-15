[297.serialize-and-deserialize-binary-tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)  

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Example:** 

You may serialize the following tree:

    1
   / \\
  2   3
     / \\
    4   5

as `"[1,2,3,null,null,4,5]"`

**Clarification:** The above format is the same as [how LeetCode serializes a binary tree](/faq/#binary-tree). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Note:** Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.  



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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        dfs(root, str);
        return str;
    }

    void dfs(TreeNode* root, string &str) {
        if(!root) {
            str += "#,";
            return;
        }
        str += to_string(root->val) + ",";
        dfs(root->left, str);
        dfs(root->right, str);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs2(data, idx);
    }
    TreeNode* dfs2(string &str, int &idx) {
        if(idx >= str.size() || str[idx] == '#'){
            idx += 2;
            return NULL;
        }
        int n = 0;
        int sign = 1;
        if(str[idx]== '-'){
            sign = -1;
            ++idx;
        }
        while(str[idx] !=','){
            n = n * 10 + str[idx++] - '0';
        }
        ++idx;
        TreeNode* node = new TreeNode(n*sign);
        node->left = dfs2(str, idx);
        node->right = dfs2(str, idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
      