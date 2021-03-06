[719.find-k-th-smallest-pair-distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)  

Given an integer array, return the k-th smallest **distance** among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

**Example 1:**  

  
**Input:**
  
nums = \[1,3,1\]
  
k = 1
  
**Output: 0** 
  
**Explanation:**
  
Here are all the pairs:
  
(1,3) -> 2
  
(1,1) -> 0
  
(3,1) -> 2
  
Then the 1st smallest distance pair is (1,1), and its distance is 0.
  

**Note:**  

1.  `2 <= len(nums) <= 10000`.
2.  `0 <= nums[i] < 1000000`.
3.  `1 <= k <= len(nums) * (len(nums) - 1) / 2`.  



**Solution:**  

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        if( nums.size() == 0 ) return 0;
        sort( nums.begin(), nums.end() );
        int left = 0, right = nums.back()-nums[0];
        while( left < right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            int j = 1;
            for( int i = 0; i< nums.size(); i++){
                while( j<nums.size() && nums[j]-nums[i]<=mid)++j;
                cnt += j-i-1;
            }
            if( cnt < k )
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};
```
      