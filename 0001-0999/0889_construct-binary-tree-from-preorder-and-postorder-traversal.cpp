//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ 
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
    map<int, TreeNode*> m;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if( pre.size() == 0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        vector<TreeNode*> vec = {root};
        int at = 0;
        for( int i = 1; i < pre.size(); i++){
            TreeNode *node = new TreeNode( pre[i]);
            if( vec.back()->left == NULL )
                vec.back()->left = node;
            else
                vec.back()->right = node;
            vec.push_back(node);
            while(vec.size() && at < post.size() && post[at] == vec.back()->val ){
                at++;
                vec.pop_back();
            }
        }
        return root;
    }
};