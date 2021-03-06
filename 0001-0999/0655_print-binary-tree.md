[655.print-binary-tree](https://leetcode.com/problems/print-binary-tree/)  

Print a binary tree in an m\*n 2D string array following these rules:

1.  The row number `m` should be equal to the height of the given binary tree.
2.  The column number `n` should always be an odd number.
3.  The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (**left-bottom part and right-bottom part**). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
4.  Each unused space should contain an empty string `""`.
5.  Print the subtrees following the same rules.

**Example 1:**  

  
**Input:**
  
     1
  
    /
  
   2
  
**Output:**
  
\[\["", "1", ""\],
  
 \["2", "", ""\]\]
  

**Example 2:**  

  
**Input:**
  
     1
  
    / \\
  
   2   3
  
    \\
  
     4
  
**Output:**
  
\[\["", "", "", "1", "", "", ""\],
  
 \["", "2", "", "", "", "3", ""\],
  
 \["", "", "4", "", "", "", ""\]\]
  

**Example 3:**  

  
**Input:**
  
      1
  
     / \\
  
    2   5
  
   / 
  
  3 
  
 / 
  
4 
  
**Output:**
  

  
\[\["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""\]
  
 \["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""\]
  
 \["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""\]
  
 \["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""\]\]
  

**Note:** The height of binary tree is in the range of \[1, 10\].  



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
    int getHeight(TreeNode* root){
        if( !root ) return 0;
        return max(getHeight(root->left), getHeight(root->right) )+1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if( !root ) return { };
        int h = getHeight(root);
        int w = pow(2, h) - 1;
        queue<pair<TreeNode*, pair<int, int> > > q;
        vector<vector<string> > ans(h, vector<string>(w) );
        q.push({root, { 0, w -1 } });
        int curH = 0;
        while(q.size() > 0 ){
            int size = q.size();
            while( size-- > 0 ){
                auto node = q.front().first;
                int left = q.front().second.first;
                int right = q.front().second.second;
                int mid = left + (right-left)/2;
                q.pop();
                ans[curH][mid] = to_string(node->val);
                if( node->left){
                    q.push({node->left, { left, mid} });
                }
                if( node->right){
                    q.push({node->right, {mid+1, right}});
                }
            }
            ++curH;
        }
        return ans;
    }
};
```
      