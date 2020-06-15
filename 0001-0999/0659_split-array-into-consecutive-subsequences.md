[659.split-array-into-consecutive-subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)  

Given an array `nums` sorted in ascending order, return `true` if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.

**Example 1:**

**Input:** \[1,2,3,3,4,5\]
**Output:** True
**Explanation:**
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

**Example 2:**

**Input:** \[1,2,3,3,4,4,5,5\]
**Output:** True
**Explanation:**
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5

**Example 3:**

**Input:** \[1,2,3,4,4,5\]
**Output:** False

**Constraints:**

*   `1 <= nums.length <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if( nums.size()  <= 2 ) return false;
        int size = nums.back();
        unordered_map<int, int> freq, req;
        for( int n : nums ){
            ++freq[n];
        }
        for( int n : nums){
            if( freq[n] == 0 ) continue;
            if( req[n] > 0 ){
                --req[n];
                ++req[n+1];
            }else if( freq[n+1] > 0 && freq[n+2] > 0 ){
                --freq[n+1];
                --freq[n+2];
                ++req[n+3];
            }else
                return false;
            --freq[n];
        }
        return true;
    }
};
```
      