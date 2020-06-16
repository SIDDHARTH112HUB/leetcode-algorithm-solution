[623.add-one-row-to-tree](https://leetcode.com/problems/add-one-row-to-tree/)  

Given the root of a binary tree, then value `v` and depth `d`, you need to add a row of nodes with value `v` at the given depth `d`. The root node is at depth 1.

The adding rule is: given a positive integer depth `d`, for each NOT null tree nodes `N` in depth `d-1`, create two tree nodes with value `v` as `N's` left subtree root and right subtree root. And `N's` **original left subtree** should be the left subtree of the new left subtree root, its **original right subtree** should be the right subtree of the new right subtree root. If depth `d` is 1 that means there is no depth d-1 at all, then create a tree node with value **v** as the new root of the whole original tree, and the original tree is the new root's left subtree.

**Example 1:**  

  
**Input:** 
  
A binary tree as following:
  
       4
  
     /   \\
  
    2     6
  
   / \\   / 
  
  3   1 5   
  

  
**v = 1**
  

  
**d = 2**
  

  
**Output:** 
  
       4
  
      / \\
  
     1   1
  
    /     \\
  
   2       6
  
  / \\     / 
  
 3   1   5   
  

  

**Example 2:**  

  
**Input:** 
  
A binary tree as following:
  
      4
  
     /   
  
    2    
  
   / \\   
  
  3   1    
  

  
**v = 1**
  

  
**d = 3**
  

  
**Output:** 
  
      4
  
     /   
  
    2
  
   / \\    
  
  1   1
  
 /     \\  
  
3       1
  

**Note:**  

1.  The given d is in range \[1, maximum depth of the given tree + 1\].
2.  The given binary tree has at least one tree node.  



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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return NULL;
        if( d == 1){
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        if( d == 2) {
            auto l = new TreeNode(v);
            l->left = root->left;
            root->left = l;
            auto r = new TreeNode(v);
            r->right = root->right;
            root->right = r;
            return root;
        }
        addOneRow(root->left, v, d - 1);
        addOneRow(root->right, v, d-1);
        return root;
    }
    
    TreeNode* addOneRow2(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            while(size-- > 0){
                auto node = q.front();
                q.pop();
                auto l = node->left;
                if( d == 2) {
                    l = new TreeNode(v);
                    l->left = node->left;
                    node->left = l;
                }
                if(l)
                    q.push(l);

                auto r = node->right;
                if( d== 2){
                    r = new TreeNode(v);
                    r->right = node->right;
                    node->right = r;
                }
                if(r)
                    q.push(r);
                
                
            }
            if(d == 2)
                return root;
            --d;
        }
        return root;
    }
};
```
      