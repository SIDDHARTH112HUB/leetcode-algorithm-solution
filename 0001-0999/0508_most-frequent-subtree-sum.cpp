//Link: https://leetcode.com/problems/most-frequent-subtree-sum/ 
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
    unordered_map<int, int> m;
    int mx = INT_MIN;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        
        vector<int> ans;
        for(auto it : m) {
            if(it.second == mx) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val + l + r;
        
        ++m[sum];
        mx = max(mx, m[sum]);
        return sum;
    }
};