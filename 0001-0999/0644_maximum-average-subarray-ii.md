[644.maximum-average-subarray-ii](https://leetcode.com/problems/maximum-average-subarray-ii/)  

Given an array consisting of `n` integers, find the contiguous subarray whose **length is greater than or equal to** `k` that has the maximum average value. And you need to output the maximum average value.

**Example 1:**  

  
**Input:** \[1,12,-5,-6,50,3\], k = 4
  
**Output:** 12.75
  
**Explanation:**
  
when length is 5, maximum average value is 10.8,
  
when length is 6, maximum average value is 9.16667.
  
Thus return 12.75.
  

**Note:**  

1.  1 <= `k` <= `n` <= 10,000.
2.  Elements of the given array will be in range \[-10,000, 10,000\].
3.  The answer with the calculation error less than 10\-5 will be accepted.  



**Solution:**  

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MIN, r = INT_MAX;
        while(l + 0.0000001 < r) {
            double mid = (l + r) / 2;
            bool res = helper(nums, mid, k);
            if(res) 
                l = mid;
            else
                r = mid;
        }
        return l;
    }
    
    bool helper(vector<int>& nums, double mid, int k) {
        double sum = 0, prev = 0, min_prev = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i] - mid;
            if(i >= k) {
                prev += nums[i-k] - mid;
                min_prev = min(prev, min_prev);
            }
            if(i >= k - 1 && sum > min_prev) return true;
        }
        return false;
    }
};
```
      