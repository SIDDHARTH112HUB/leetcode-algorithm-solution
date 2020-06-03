//Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/ 
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
    map<TreeNode*, TreeNode*> parent;
    int findParent(TreeNode* root){
        if( !root ) return 0;
        int l = 1, r= 1;
        if( root->left){
            parent[root->left ] = root;
            
            l = 1+findParent(root->left);
        }
        if( root->right){
            parent[root->right] = root;
            r = 1+findParent(root->right);
        }
        return max(l, r);
    }
    
    void findDeepest(TreeNode* root, int h, set<TreeNode*> &dict ){
        if(h == 1){
            if( root->left || root->right )
                cout<<"not the deepest "<<endl;
            dict.insert(root);
            return;
        }
        if( root->left ){
            findDeepest(root->left, h-1, dict);
        }
        if( root->right ){
            findDeepest(root->right, h-1, dict);
        }
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if( !root ) return NULL;
        int h = findParent(root);
        set<TreeNode*> node;
        //cout<<"height "<<h<<endl;
        if( h == 1 )
            return root;
        findDeepest(root, h, node );
        if( node.size() == 1 )
            return *node.begin();
        while(node.size()){
            set<TreeNode*> tmp;
            for( auto n:node){
                tmp.insert(parent[n]);
            }
            if( tmp.size() == 1 )
                return *tmp.begin();
            else
                node = tmp;
        }
        return NULL;
    }
};