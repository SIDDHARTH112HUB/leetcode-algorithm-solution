//Link: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/ 
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
    TreeNode *t;
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> v;
    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, k);
        parent.erase(NULL);
        return bfs(t);
    }
    
    void dfs(TreeNode* root, int k) {
        if(!root) return;
        parent[root->left] = root;
        parent[root->right] = root;
        if(root->val == k) t = root;
        dfs(root->left, k);
        dfs(root->right, k);
    }
    
    int bfs(TreeNode* root) {
        v.insert(root);
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            auto node = q.front();q.pop();
            if(!node->left && !node->right) return node->val;
            if(node->left && v.count(node->left) == 0) {
                q.push(node->left);
                v.insert(node->left);
            }
            if(node->right && v.count(node->right) == 0) {
                q.push(node->right);
                v.insert(node->right);
            }
            if(parent[node] && v.count(parent[node]) == 0) {
                q.push(parent[node]);
                v.insert(parent[node]);
            }
        }
        return -1;
    }
};