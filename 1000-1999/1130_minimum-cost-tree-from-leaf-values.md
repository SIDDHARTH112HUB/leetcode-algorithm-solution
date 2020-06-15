[1130.minimum-cost-tree-from-leaf-values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)  

Given an array `arr` of positive integers, consider all binary trees such that:

*   Each node has either 0 or 2 children;
*   The values of `arr` correspond to the values of each **leaf** in an in-order traversal of the tree.  _(Recall that a node is a leaf if and only if it has 0 children.)_
*   The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

**Example 1:**

**Input:** arr = \[6,2,4\]
**Output:** 32
**Explanation:**
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \\          /  \\
  12   4        6    8
 /  \\               / \\
6    2             2   4

**Constraints:**

*   `2 <= arr.length <= 40`
*   `1 <= arr[i] <= 15`
*   It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than `2^31`).  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, pair<int, int> > > m;
    int mctFromLeafValues(vector<int>& arr) {
        return helper(arr, 0, arr.size()-1).first;
    }
    
    pair<int, int> helper(vector<int>& arr, int i, int j){
        if( i == j)
            return { 0, arr[i] };
        if( j - i == 1)
            return { arr[i] * arr[j], max(arr[i], arr[j]) };
        if(m[i].count(j)) return m[i][j];
        int ans = INT_MAX;
        int leaf = 0;
        for(int k = 0; k < j - i; ++k){
            auto r1 = helper(arr, i, i + k);
            auto r2 = helper(arr, i + k + 1, j);
            int tmp = r1.second * r2.second;
            ans = min(r1.first + r2.first + tmp, ans);
            leaf = max(r1.second, r2.second);
        }
        m[i][j] = {ans, leaf};
        return {ans, leaf};
    }
};
```
      