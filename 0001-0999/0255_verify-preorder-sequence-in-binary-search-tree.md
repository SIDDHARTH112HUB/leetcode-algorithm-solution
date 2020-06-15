[255.verify-preorder-sequence-in-binary-search-tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)  

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \\
   2   6
  / \\
 1   3

**Example 1:**

**Input:** \[5,2,6,1,3\]
**Output:** false

**Example 2:**

**Input:** \[5,2,1,3,6\]
**Output:** true

**Follow up:**  
Could you do it using only constant space complexity?  



**Solution:**  

```cpp
class Solution {
public:
    int start = 0;
    bool verifyPreorder(vector<int>& preorder) {
        dfs(preorder, INT_MIN, INT_MAX);
        return start ==preorder.size();
    }
    
    void dfs(vector<int>& o, int mn, int mx) {
        if(start >= o.size() || mn > o[start] || o[start] > mx) return;
        int val = o[start++];
        dfs(o, mn, val);
        dfs(o, val, mx);
    }
};
```
      