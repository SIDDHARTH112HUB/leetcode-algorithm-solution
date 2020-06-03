//Link: https://leetcode.com/problems/print-binary-tree/ 
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
    int getHeight(TreeNode* root){
        if( !root ) return 0;
        return max(getHeight(root->left), getHeight(root->right) )+1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if( !root ) return { };
        int h = getHeight(root);
        int w = pow(2, h) - 1;
        queue<pair<TreeNode*, pair<int, int> > > q;
        vector<vector<string> > ans(h, vector<string>(w) );
        q.push({root, { 0, w -1 } });
        int curH = 0;
        while(q.size() > 0 ){
            int size = q.size();
            while( size-- > 0 ){
                auto node = q.front().first;
                int left = q.front().second.first;
                int right = q.front().second.second;
                int mid = left + (right-left)/2;
                q.pop();
                ans[curH][mid] = to_string(node->val);
                if( node->left){
                    q.push({node->left, { left, mid} });
                }
                if( node->right){
                    q.push({node->right, {mid+1, right}});
                }
            }
            ++curH;
        }
        return ans;
    }
};