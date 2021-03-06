[449.serialize-and-deserialize-bst](https://leetcode.com/problems/serialize-and-deserialize-bst/)  

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a **binary search tree**. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

**The encoded string should be as compact as possible.**

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
        if(!root) return "#,";
        string str = to_string(root->val);
        str += ",";
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return helper(data, idx);
    }
    TreeNode* helper(string &data, int &idx) {
        if( idx >= data.size()) return NULL;
        int num = 0;
        int sign = 1;
        while(idx < data.size()) {
            if( data[idx] == '#' ){
                idx += 2;
                return NULL;
            }
            if(data[idx] == ','){
                idx++;
                break;
            }
            if(data[idx] == '-'){
                idx++;
                sign = -1;
                continue;
            }
            num = num * 10 + data[idx++] - '0';
        }
        num *= sign;
        TreeNode* node = new TreeNode(num);
        node->left = helper(data, idx);
        node->right =  helper(data, idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
      