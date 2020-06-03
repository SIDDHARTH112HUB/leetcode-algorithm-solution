//Link: https://leetcode.com/problems/unique-binary-search-trees-ii/ 
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
    map<int, map<int, vector<TreeNode*> > > dp;
    vector<TreeNode*> generateTrees(int n) {
        if( n == 0 )return {};
        return solve(1, n);
    }
    
    vector<TreeNode*> solve(int min, int max){
        if( min > max ) return {nullptr};
        if( min == max) return {new TreeNode(min)};
        auto min_it = dp.find(min);
        if( min_it != dp.end()){
            auto max_it = min_it->second.find(max);
            if( max_it != min_it->second.end() )
                return max_it->second;
        }
        vector<TreeNode*> vec;
        for( int i = min; i<=max; i++ ){
            vector<TreeNode*> lvec = solve(min, i-1);
            vector<TreeNode*> rvec = solve(i+1, max);
            for( auto &left:lvec){
                for( auto &right:rvec){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    vec.push_back(root);
                }
            }
        }
        dp[min][max] = vec;
        return vec;
    }
};