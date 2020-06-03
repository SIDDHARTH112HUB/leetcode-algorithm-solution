//Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> m;
    FindElements(TreeNode* root) {
        if(!root) return;
        dfs(root, 0);
    }
    
    void dfs(TreeNode* root, int val) {
        if(!root) return;
        m.insert(val);
        root->val = val;
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val *2  + 2);
    }
    bool find(int target) {
        return m.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */