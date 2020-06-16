[907.sum-of-subarray-minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)  

Given an array of integers `A`, find the sum of `min(B)`, where `B` ranges over every (contiguous) subarray of `A`.

Since the answer may be large, **return the answer modulo `10^9 + 7`.**

**Example 1:**

  
**Input:** \[3,1,2,4\]
  
**Output:** 17
  
**Explanation:** Subarrays are \[3\], \[1\], \[2\], \[4\], \[3,1\], \[1,2\], \[2,4\], \[3,1,2\], \[1,2,4\], \[3,1,2,4\]. 
  
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.

**Note:**

1.  `1 <= A.length <= 30000`
2.  `1 <= A[i] <= 30000`  



**Solution:**  

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        vector<pair<int, int> > stk;
        stk.push_back({0, -1});
        long long ans = 0;
        for(int i = 0; i <= A.size(); ++i) {
            int n =((i == A.size()) ? 0 : A[i]);
            while(stk.back().first > n){
                auto p = stk.back();
                int idx = p.second;
                int n1 = p.first;
                stk.pop_back();
                int l = idx - stk.back().second;
                int r = i - idx;
                ans = (ans + (r * l * A[idx]) % M) % M;
            }
            stk.push_back({n, i});
        }
        return ans;
    }
};
```
      