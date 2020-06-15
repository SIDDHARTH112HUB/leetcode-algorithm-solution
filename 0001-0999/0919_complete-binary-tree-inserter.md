[919.complete-binary-tree-inserter](https://leetcode.com/problems/complete-binary-tree-inserter/)  

A _complete_ binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure `CBTInserter` that is initialized with a complete binary tree and supports the following operations:

*   `CBTInserter(TreeNode root)` initializes the data structure on a given tree with head node `root`;
*   `CBTInserter.insert(int v)` will insert a `TreeNode` into the tree with value `node.val = v` so that the tree remains complete, **and returns the value of the parent of the inserted `TreeNode`**;
*   `CBTInserter.get_root()` will return the head node of the tree.

**Example 1:**

**Input:** inputs = \["CBTInserter","insert","get\_root"\], inputs = \[\[\[1\]\],\[2\],\[\]\]
**Output:** \[null,1,\[1,2\]\]

**Example 2:**

**Input:** inputs = \["CBTInserter","insert","insert","get\_root"\], inputs = \[\[\[1,2,3,4,5,6\]\],\[7\],\[8\],\[\]\]
**Output:** \[null,3,4,\[1,2,3,4,5,6,7,8\]\]

**Note:**

1.  The initial given tree is complete and contains between `1` and `1000` nodes.
2.  `CBTInserter.insert` is called at most `10000` times per test case.
3.  Every value of a given or inserted node is between `0` and `5000`.  



**Solution:**  

```cpp
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
```
      