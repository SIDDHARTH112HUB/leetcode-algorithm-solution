[889.construct-binary-tree-from-preorder-and-postorder-traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)  

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals `pre` and `post` are distinct positive integers.

**Example 1:**

  
**Input:** pre = \[1,2,4,5,3,6,7\], post = \[4,5,2,6,7,3,1\]
  
**Output:** \[1,2,3,4,5,6,7\]
  

**Note:**

*   `1 <= pre.length == post.length <= 30`
*   `pre[]` and `post[]` are both permutations of `1, 2, ..., pre.length`.
*   It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.  



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
```
      