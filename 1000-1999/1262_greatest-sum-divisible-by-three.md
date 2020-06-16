[1262.greatest-sum-divisible-by-three](https://leetcode.com/problems/greatest-sum-divisible-by-three/)  

Given an array `nums` of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

**Example 1:**

  
**Input:** nums = \[3,6,5,1,8\]  
**Output:** 18  
**Explanation:** Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

**Example 2:**

  
**Input:** nums = \[4\]  
**Output:** 0  
**Explanation:** Since 4 is not divisible by 3, do not pick any number.  

**Example 3:**

  
**Input:** nums = \[1,2,3,4,4\]  
**Output:** 12  
**Explanation:** Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).  

**Constraints:**

*   `1 <= nums.length <= 4 * 10^4`
*   `1 <= nums[i] <= 10^4`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 3 == 0) return sum;
        vector<vector<int> > arr(3);
        for(auto n : nums) {
            arr[n%3].push_back(n);
        }
        sort(arr[1].begin(), arr[1].end());
        sort(arr[2].begin(), arr[2].end());
        int md = sum % 3;
        int ans = 0;
        if(md == 2) {
            if(arr[2].size() > 0)
                ans = max(ans, sum - arr[2][0]);
            if(arr[1].size() > 1)
                ans = max(ans, sum - arr[1][0] - arr[1][1] );
        }
        if(md == 1) {
            if(arr[2].size() > 1)
                ans = max(ans, sum - arr[2][0] - arr[2][1]);
            if(arr[1].size() > 0)
                ans = max(ans, sum - arr[1][0] );
        }
        return ans;
    }
};
```
      