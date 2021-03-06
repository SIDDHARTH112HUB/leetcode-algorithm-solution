[1372.longest-zigzag-path-in-a-binary-tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)  

Given a binary tree `root`, a ZigZag path for a binary tree is defined as follow:

*   Choose **any** node in the binary tree and a direction (right or left).
*   If the current direction is right then move to the right child of the current node otherwise move to the left child.
*   Change the direction from right to left or right to left.
*   Repeat the second and third step until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest **ZigZag** path contained in that tree.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png)**

  
**Input:** root = \[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1\]
  
**Output:** 3
  
**Explanation:** Longest ZigZag path in blue nodes (right -> left -> right).
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/01/22/sample_2_1702.png)**

  
**Input:** root = \[1,1,1,null,1,null,null,1,1,null,1\]
  
**Output:** 4
  
**Explanation:** Longest ZigZag path in blue nodes (left -> right -> left -> right).
  

**Example 3:**

  
**Input:** root = \[1\]
  
**Output:** 0
  

**Constraints:**

*   Each tree has at most `50000` nodes..
*   Each node's value is between `[1, 100]`.  



**Solution:**  

```cpp
class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        h(root->left, 0);
        h(root->right, 1);
        return ans;
    }
    
    int h(TreeNode* root, int d) {
        if(!root) return 0;
        int l = h(root->left, 0) + (d == 1);
        int r = h(root->right, 1) + (d == 0);
        ans = max(ans, max(l , r));
        return d == 0 ? r : l;
    }
};
```
      