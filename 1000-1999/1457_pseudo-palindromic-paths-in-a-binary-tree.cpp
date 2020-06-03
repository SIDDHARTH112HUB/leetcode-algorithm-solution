//Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/ 
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
    int ans = 0;
    vector<int> arr;
    int pseudoPalindromicPaths (TreeNode* root) {
        arr.resize(10);
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root) {
        if(!root) return;
        arr[root->val]++;
        dfs(root->left);
        dfs(root->right);
        if(!root->left && !root->right) {
            int odd = 0, even = 0;
            for(auto n : arr){
                odd += n % 2;
            }
            ans += odd <= 1;
        }
        arr[root->val]--;
    }
};