[863.all-nodes-distance-k-in-binary-tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)  

We are given a binary tree (with root node `root`), a `target` node, and an integer value `K`.

Return a list of the values of all nodes that have a distance `K` from the `target` node.  The answer can be returned in any order.

**Example 1:**

  
**Input:** root = \[3,5,1,6,2,0,8,null,null,7,4\], target = 5, K = 2
  

  
**Output:** \[7,4,1\]
  

  
**Explanation:** 
  
The nodes that are a distance 2 from the target node (with value 5)
  
have values 7, 4, and 1.
  

  
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)
  

  
Note that the inputs "root" and "target" are actually TreeNodes.
  
The descriptions of the inputs above are just serializations of these objects.
  

**Note:**

1.  The given tree is non-empty.
2.  Each node in the tree has unique values `0 <= node.val <= 500`.
3.  The `target` node is a node in the tree.
4.  `0 <= K <= 1000`.  



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

class Solution {
public:
    vector<int> ans;   
    unordered_map<TreeNode*, TreeNode*> parent;  // son=>parent  
    unordered_set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }
    void dfs( TreeNode* node, int K){
        if( visit.find(node) != visit.end() )
            return;
        visit.insert(node);
        if( K == 0 ){
            ans.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent[node];
        if( p )
            dfs(p, K-1);
    }
};
```
      