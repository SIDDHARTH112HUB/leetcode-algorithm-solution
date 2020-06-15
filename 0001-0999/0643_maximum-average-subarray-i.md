[643.maximum-average-subarray-i](https://leetcode.com/problems/maximum-average-subarray-i/)  

Given an array consisting of `n` integers, find the contiguous subarray of given length `k` that has the maximum average value. And you need to output the maximum average value.

**Example 1:**

**Input:** \[1,12,-5,-6,50,3\], k = 4
**Output:** 12.75
**Explanation:** Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

**Note:**

1.  1 <= `k` <= `n` <= 30,000.
2.  Elements of the given array will be in the range \[-10,000, 10,000\].  



**Solution:**  

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, ans=INT_MIN;
        int cnt = k;
        for( int i = 0; i < nums.size(); i++ ){
            sum += nums[i];
            if( cnt == 0 ){
                sum -= nums[i-k];
                ans = max(ans, sum );
            }else if( cnt == 1 ){
                ans = max(ans, sum );
                cnt--;
            }
            else
                cnt--;
        }
        return ans*1.0/k;
    }
};
```
      