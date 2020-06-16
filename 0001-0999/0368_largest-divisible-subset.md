[368.largest-divisible-subset](https://leetcode.com/problems/largest-divisible-subset/)  

Given a set of **distinct** positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

**Example 1:**

  
**Input:** \[1,2,3\]
  
**Output:** \[1,2\] (of course, \[1,3\] will also be ok)
  

**Example 2:**

  
**Input:** \[1,2,4,8\]
  
**Output:** \[1,2,4,8\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        if( size == 0 )return {};
        vector<int> parent(size, -1);
        vector<int> dp(size, 1);
        vector<int> ret;
        sort(nums.begin(), nums.end());
        for( int i = 0; i<size; i++){
            for( int j=0; j<i; j++){
                if( nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1 ){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if( dp[i] > dp[ans])
                ans = i;
        }
        
        while( ans != -1){
            ret.push_back(nums[ans]);
            ans = parent[ans];
        }
        return ret;
    }
};
```
      