[698.partition-to-k-equal-sum-subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)  

Given an array of integers `nums` and a positive integer `k`, find whether it's possible to divide this array into `k` non-empty subsets whose sums are all equal.

**Example 1:**

  
**Input:** nums = \[4, 3, 2, 3, 5, 2, 1\], k = 4
  
**Output:** True
  
**Explanation:** It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
  

**Note:**

*   `1 <= k <= len(nums) <= 16`.
*   `0 < nums[i] < 10000`.  



**Solution:**  

```cpp
class Solution {
public:
    bool fun(vector<int>& nums, int idx, int sum){
        if( sum == 0 ){
            return true;
        }
        for( int i = 0; i<nums.size(); i++){
            if( nums[i] == 0 )
                continue;
            if( sum - nums[i]>=0 ){
                int tmp = nums[i];
                nums[i] = 0;
                if( fun(nums, i, sum-tmp ) ){
                    return true;
                }
                nums[i] = tmp;
            }else{
                return false;
            }
        }
        return false;   
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for( int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum /= k;
        for(int  i= 0; i<k; i++){
            if(!fun(nums, 0, sum)){
                return false;
            }
        }
        return true;
    }
};
```
      