[968.binary-tree-cameras](https://leetcode.com/problems/binary-tree-cameras/)  

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor **its parent, itself, and its immediate children**.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png)

  
**Input:** \[0,0,null,0,0\]
  
**Output:** 1
  
**Explanation:** One camera is enough to monitor all nodes if placed as shown.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png)

  
**Input:** \[0,0,null,0,null,0,null,null,0\]
  
**Output:** 2
  
**Explanation:** At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
  

  
**Note:**

1.  The number of nodes in the given tree will be in the range `[1, 1000]`.
2.  **Every** node has value 0.  



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

const int NO_CAMERA = 0;
const int HAS_CAMERA= 1;
const int NO_NEEDED = 2;
class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        if( !root ) return 0;
        return (dfs(root) == NO_CAMERA ? 1:0)+res;
    }
    
    int dfs(TreeNode* root){
        
        //if( !root->left && !root->right) return 0;
        int left = root->left ? dfs(root->left) : NO_NEEDED;
        int right = root->right? dfs(root->right) : NO_NEEDED;
        if( left == NO_CAMERA || right == NO_CAMERA ){
            ++res;
            return HAS_CAMERA;
        }
        return (left==HAS_CAMERA || right ==HAS_CAMERA ) ? NO_NEEDED : NO_CAMERA;
    }
};
```
      