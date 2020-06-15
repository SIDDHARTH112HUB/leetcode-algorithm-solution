[169.majority-element](https://leetcode.com/problems/majority-element/)  

Given an array of size _n_, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.

**Example 1:**

**Input:** \[3,2,3\]
**Output:** 3

**Example 2:**

**Input:** \[2,2,1,1,1,2,2\]
**Output:** 2  



**Solution:**  

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num1 = nums[0],  cnt = 0;
        for( auto n : nums){
            if( num1 == n){
                cnt++;
            }else{
                cnt--;
            }
            if( cnt == 0 ){
                num1 = n;
                cnt = 1;
            }
        }
        return num1;
    }
};
```
      