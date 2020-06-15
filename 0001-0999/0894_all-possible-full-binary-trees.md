[894.all-possible-full-binary-trees](https://leetcode.com/problems/all-possible-full-binary-trees/)  

A _full binary tree_ is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with `N` nodes.  Each element of the answer is the root node of one possible tree.

Each `node` of each tree in the answer **must** have `node.val = 0`.

You may return the final list of trees in any order.

**Example 1:**

**Input:** 7
**Output:** \[\[0,0,0,null,null,0,0,null,null,0,0\],\[0,0,0,null,null,0,0,0,0\],\[0,0,0,0,0,0,0\],\[0,0,0,0,0,null,null,null,null,0,0\],\[0,0,0,0,0,null,null,0,0\]\]
**Explanation:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png)

**Note:**

*   `1 <= N <= 20`  



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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 0 || N % 2 == 0) return { };
        if(N == 1) return { new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 2; i < N; i+=2) {
            auto arr1 = allPossibleFBT(i - 1);
            auto arr2= allPossibleFBT(N - i);
            for(auto l : arr1) {
                for(auto r : arr2) {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
```
      