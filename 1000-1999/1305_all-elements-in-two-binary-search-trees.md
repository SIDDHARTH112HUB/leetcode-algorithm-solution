[1305.all-elements-in-two-binary-search-trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)  

Given two binary search trees `root1` and `root2`.

Return a list containing _all the integers_ from _both trees_ sorted in **ascending** order.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png)

  
**Input:** root1 = \[2,1,4\], root2 = \[1,0,3\]  
**Output:** \[0,1,1,2,3,4\]  

**Example 2:**

  
**Input:** root1 = \[0,-10,10\], root2 = \[5,1,7,0,2\]  
**Output:** \[-10,0,0,1,2,5,7,10\]  

**Example 3:**

  
**Input:** root1 = \[\], root2 = \[5,1,7,0,2\]  
**Output:** \[0,1,2,5,7\]  

**Example 4:**

  
**Input:** root1 = \[0,-10,10\], root2 = \[\]  
**Output:** \[-10,0,10\]  

**Example 5:**

![](https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png)

  
**Input:** root1 = \[1,null,8\], root2 = \[8,1\]  
**Output:** \[1,1,8,8\]  

**Constraints:**

*   Each tree has at most `5000` nodes.
*   Each node's value is between `[-10^5, 10^5]`.  



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
    vector<int> a;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        h(root1);h(root2);
        sort(a.begin(), a.end());
        return a;
    }
    void h(TreeNode* root) {
        if(!root) return;
        a.push_back(root->val);
        h(root->left);
        h(root->right);
    }
};
```
      