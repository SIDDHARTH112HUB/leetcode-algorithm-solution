[823.binary-trees-with-factors](https://leetcode.com/problems/binary-trees-with-factors/)  

Given an array of unique integers, each integer is strictly greater than 1.

We make a binary tree using these integers and each number may be used for any number of times.

Each non-leaf node's value should be equal to the product of the values of it's children.

How many binary trees can we make?  Return the answer **modulo 10 \*\* 9 + 7**.

**Example 1:**

  
**Input:** `A = [2, 4]`
  
**Output:** 3
  
**Explanation:** We can make these trees: `[2], [4], [4, 2, 2]`

**Example 2:**

  
**Input:** `A = [2, 4, 5, 10]`
  
**Output:** `7`
  
**Explanation:** We can make these trees: `[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]`.

**Note:**

1.  `1 <= A.length <= 1000`.
2.  `2 <= A[i] <= 10 ^ 9`.  



**Solution:**  

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& A) {
        unordered_map<long, long> m;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); ++i) {
            m[A[i]] += 1;
            for(int j = 0; j < i; ++j) {
                long mod = A[i] % A[j];
                long div = A[i] / A[j];
                if(mod == 0 && m.count(div)) {
                    m[A[i]] += (m[A[j]] * m[div])%M;
                }
            }
        }
        long ans = 0;
        for(auto &it : m)ans = (ans + it.second) % M;
        return ans;
    }
};
```
      