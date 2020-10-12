[1590.make-sum-divisible-by-p](https://leetcode.com/problems/make-sum-divisible-by-p/)  

Given an array of positive integers `nums`, remove the **smallest** subarray (possibly **empty**) such that the **sum** of the remaining elements is divisible by `p`. It is **not** allowed to remove the whole array.

Return _the length of the smallest subarray that you need to remove, or_ `-1` _if it's impossible_.

A **subarray** is defined as a contiguous block of elements in the array.

**Example 1:**

  
**Input:** nums = \[3,1,4,2\], p = 6  
**Output:** 1  
**Explanation:** The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray \[4\], and the sum of the remaining elements is 6, which is divisible by 6.  

**Example 2:**

  
**Input:** nums = \[6,3,5,2\], p = 9  
**Output:** 2  
**Explanation:** We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray \[5,2\], leaving us with \[6,3\] with sum 9.  

**Example 3:**

  
**Input:** nums = \[1,2,3\], p = 3  
**Output:** 0  
**Explanation:** Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.  

**Example 4:**

  
**Input:** nums = \[1,2,3\], p = 7  
**Output:** -1  
**Explanation:** There is no way to remove a subarray in order to get a sum divisible by 7.  

**Example 5:**

  
**Input:** nums = \[1000000000,1000000000,1000000000\], p = 3  
**Output:** 0  

**Constraints:**

*   `1 <= nums.length <= 105`
*   `1 <= nums[i] <= 109`
*   `1 <= p <= 109`  



**Solution:**  

```cpp
class Solution {
public:
    
    int minSubarray(vector<int>& nums, int p) {
        int l = 1;
        long long sum = 0;
        map<long long, long long> m;
        for(long long n : nums) sum += n;
        if(sum %p == 0) return 0;
        // for(int i = 1; i < nums.size(); ++i) {
        //     nums[i] += nums[i - 1];
        // }
        long long ans = INT_MAX;
        long long ls = 0, rs = sum;
        // cout<<"begin"<<endl;
        for(long long i = 0; i < nums.size() - 1; ++i) {
            rs -= nums[i];
            if(rs % p == 0) ans = min(ans, i + 1);
            // cout<<rs<<" "<<i<<" "<<rs%p<<endl;
            if(m.count(p - rs % p)) {
                
                ans = min(ans, i - m[p - rs % p]);
            }
            ls += nums[i];
            if(ls % p == 0) {
                ans = min(ans, (long long)nums.size() - i - 1);
            }
            m[ls % p] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```
      