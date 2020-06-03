//Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/ 

class Solution {
public:
    int ans = 0;
    int maxSumBST(TreeNode* root) {
        h(root);
        return ans;
    }
    
    //return value {isBST, sum_of_tree, min_value_of_tree, max_value_of_tree }
    vector<int> h(TreeNode* root) {
        if(!root) return {true, 0};
        auto res1 = h(root->left);
        auto res2 = h(root->right);
        if(res1[0] && (!root->left || res1[3] < root->val)) {
            if(res2[0] && (!root->right ||  res2[2] > root->val)) {
                int sum = res1[1] + res2[1] + root->val;
                ans = max(ans, sum);
                return {true, sum, root->left ? res1[2] : root->val, root->right ? res2[3] : root->val};
            }
        }
        return {false, 0};
    }
};