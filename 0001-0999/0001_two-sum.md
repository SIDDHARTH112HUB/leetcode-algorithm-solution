[1.two-sum](https://leetcode.com/problems/two-sum/)  

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **_exactly_** one solution, and you may not use the _same_ element twice.

**Example:**

Given nums = \[2, 7, 11, 15\], target = 9,

Because nums\[**0**\] + nums\[**1**\] = 2 + 7 = 9,
return \[**0**, **1**\].  



**Solution:**  

```cpp

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int sum){
    unordered_map<int, int> m;
    for( int i = 0; i < nums.size(); i++ ){
      int n = nums[i];
      if( m.count(sum - n) ){
        return {m[sum-n], i};
      }
      m[n] = i;
    }
    return {-1, -1};
  }

};

```
      