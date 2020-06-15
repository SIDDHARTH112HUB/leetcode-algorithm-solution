[272.closest-binary-search-tree-value-ii](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)  

Given a non-empty binary search tree and a target value, find _k_ values in the BST that are closest to the target.

**Note:**

*   Given target value is a floating point.
*   You may assume _k_ is always valid, that is: _k_ ≤ total nodes.
*   You are guaranteed to have only one unique set of _k_ values in the BST that are closest to the target.

**Example:**

**Input:** root = \[4,2,5,1,3\], target = 3.714286, and _k_ = 2

    4
   / \\
  2   5
 / \\
1   3

**Output:** \[4,3\]

**Follow up:**  
Assume that the BST is balanced, could you solve it in less than _O_(_n_) runtime (where _n_ = total nodes)?  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>> q;
        inorder(root, target, k, q);
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        q.push({abs(root->val - target), root->val});
        if (q.size() > k) q.pop();
        inorder(root->right, target, k, q);
    }
};
```
      