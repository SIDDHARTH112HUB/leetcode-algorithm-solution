//Link: https://leetcode.com/problems/complete-binary-tree-inserter/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root;
    //unordered_map<int, TreeNode*> m;
    vector<TreeNode*> v;
    CBTInserter(TreeNode* root) {
        this->root = NULL;
        if( !root ){
            return;
        }
        this->root = root;
        this->build(root);
        
    }
    void build(TreeNode* root) {
        if(!root ) return;
        queue<TreeNode*> q;
        q.push(root);
        while( q.size()>0){
            int size = q.size();
            while(size-->0){
                auto node = q.front();
                v.push_back( node );
                if( node->left) 
                    q.push(node->left);
                if( node->right )
                    q.push(node->right);
                q.pop();
            }
        }
    }
    int insert(int val) {
        
        auto node = new TreeNode(val);
        v.push_back(node);
        if( !root ){
            root = node;
            return root->val;
        }
        auto parent = v[v.size()/2-1];
        if( !parent->left )
            parent->left = node;
        else
            parent->right = node;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */