//Link: https://leetcode.com/problems/all-possible-full-binary-trees/ 
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 0 || N % 2 == 0) return { };
        if(N == 1) return { new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 2; i < N; i+=2) {
            auto arr1 = allPossibleFBT(i - 1);
            auto arr2= allPossibleFBT(N - i);
            for(auto l : arr1) {
                for(auto r : arr2) {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};