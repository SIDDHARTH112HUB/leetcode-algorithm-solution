//Link: https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/ 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return NULL;
        TreeNode* node = new TreeNode(root->val);
        if (root->children.size() == 0) return node;
        node->left = encode(root->children[0]);
        auto ans = node;
        node = node->left;
        for(int i = 1; i < root->children.size(); ++i) {
            node->right = encode(root->children[i]);
            node = node->right;
        }
        return ans;
    }
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node* node = new Node(root->val);
        if(root->left) node->children.push_back(decode(root->left));
        root = root->left;
        while(root && root->right) {
            node->children.push_back(decode(root->right));
            root = root->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));