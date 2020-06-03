//Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/ 
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(q.size()) {
            int size = q.size();
            int cnt = size;
            long long sum = 0;
            while(size--  > 0) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(cnt)
                ans.push_back(sum*1.0/cnt);
        }
        return ans;
    }
};