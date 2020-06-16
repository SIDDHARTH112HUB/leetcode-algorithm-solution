[1028.recover-a-tree-from-preorder-traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)  

We run a preorder depth first search on the `root` of a binary tree.

At each node in this traversal, we output `D` dashes (where `D` is the _depth_ of this node), then we output the value of this node.  _(If the depth of a node is `D`, the depth of its immediate child is `D+1`.  The depth of the root node is `0`.)_

If a node has only one child, that child is guaranteed to be the left child.

Given the output `S` of this traversal, recover the tree and return its `root`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/04/08/recover-a-tree-from-preorder-traversal.png)**

  
**Input:** "1-2--3--4-5--6--7"
  
**Output:** \[1,2,5,3,4,6,7\]
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114101-pm.png)**

  
**Input:** "1-2--3---4-5--6---7"
  
**Output:** \[1,2,5,3,null,6,null,4,null,7\]

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114955-pm.png)

  
**Input:** "1-401--349---90--88"
  
**Output:** \[1,401,null,349,88,90\]
  

**Note:**

*   The number of nodes in the original tree is between `1` and `1000`.
*   Each node will have a value between `1` and `10^9`.  



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
    int idx = 0;
    
    void setChildNode(string &S, TreeNode* &childNode, int d) {
        int depth = 0;
        int i = idx;
        //find next number depth.
        for (i = idx; i < S.size(); ++i) {
            if (S[i] != '-')
                break;
            ++depth;
        }
        // same depth, the next number is child node.
        if (depth == d) {
            idx = i;
            childNode = recoverFromPreorder(S, d+1);
        }
    }
    TreeNode* recoverFromPreorder(string &S, int d = 1) {
        int sum = 0;
        if (S.size() == 0 ) return NULL;
        for (;idx < S.size(); idx++) {
            if (S[idx] == '-')
                break;
            sum = 10 * sum + S[idx] - '0';
        }
        TreeNode* root = new TreeNode(sum);
        if ( idx == S.size() )
            return root;
        
        setChildNode(S, root->left, d);
        setChildNode(S, root->right, d);
        return root;
    }
};
```
      