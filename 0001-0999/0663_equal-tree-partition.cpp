//Link: https://leetcode.com/problems/equal-tree-partition/ 

class Solution {
public:
    int sum = 0;
    bool res = false;
    TreeNode* root;
    bool checkEqualTree(TreeNode* root) {
        this->root = root;
        sumTree(root);
        if(sum % 2) return false;
        findPart(root);
        return res;
    }

    void sumTree(TreeNode *root) {
        if(!root) return;
        sum += root->val;
        sumTree(root->left);
        sumTree(root->right);
    }
    
    int findPart(TreeNode *root) {
        if(!root) return 0;
        int l = findPart(root->left);
        int r = findPart(root->right);
        int partSum = l + r + root->val;
        if(root->left && sum - l == l) res = true;
        else if(root->right && sum - r == r) res = true;
        else if(sum - partSum == partSum && this->root != root) res = true;
        return partSum;
    }
};