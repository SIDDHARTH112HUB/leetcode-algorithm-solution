[932.beautiful-array](https://leetcode.com/problems/beautiful-array/)  

For some fixed `N`, an array `A` is _beautiful_ if it is a permutation of the integers `1, 2, ..., N`, such that:

For every `i < j`, there is **no** `k` with `i < k < j` such that `A[k] * 2 = A[i] + A[j]`.

Given `N`, return **any** beautiful array `A`.  (It is guaranteed that one exists.)

**Example 1:**

  
**Input:** 4
  
**Output:** \[2,1,4,3\]
  

**Example 2:**

  
**Input:** 5
  
**Output:** \[3,1,2,5,4\]

**Note:**

*   `1 <= N <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans = {1};
        while( ans.size() < N ){
            vector<int> tmp;
            for( auto n : ans) if( n * 2-1<=N)tmp.push_back( n*2-1);
            for( auto n : ans)  if( n * 2<=N)tmp.push_back( n * 2);
            ans =tmp;
        }
        return ans;
    }
};
```
      