//Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ 
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