//Link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/ 
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "";
        string ans = to_string(root->val);
        for(int i = 0; i < root->children.size(); ++i) {
            ans += "(" + serialize(root->children[i]) + ")";
        }
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int idx = 0;
        return dfs(data, idx);
    }
    
    
    Node* dfs(string &data, int &idx) {
        int sum = 0;
        Node* node = NULL;
        int sign = 1;
        while(idx < data.size()) {
            int c = data[idx];
            if(c <= '9' && c >= '0' ) {
                ++idx;
                sum = sum * 10 + c - '0';
                node = new Node(0);
            }
            else if(c == '(') {
                ++idx;
                auto child = dfs(data, idx);
                if(child) node->children.push_back(child);
            } else if(c == ')') {
                ++idx;
                break;
            } else {
                ++idx;
                sign = -1;
            }
            
        }
        if(node) node->val = sum*sign;
        return node;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));