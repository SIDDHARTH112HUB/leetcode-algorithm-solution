//Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/ 


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
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int step = 1;
        while(q.size()) {
            int size = q.size();
            int sum = 0;
            while(size-- > 0) {
                auto node = q.front();
                sum += node->val;
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(sum > ans){
                ans = sum;
                level = step;
            }
            ++step;
        }
        return level;
    }
};

