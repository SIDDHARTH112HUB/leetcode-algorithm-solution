[167.two-sum-ii-input-array-is-sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)  

Given an array of integers that is already **_sorted in ascending order_**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

*   Your returned answers (both index1 and index2) are not zero-based.
*   You may assume that each input would have _exactly_ one solution and you may not use the _same_ element twice.

**Example:**

  
**Input:** numbers = \[2,7,11,15\], target = 9
  
**Output:** \[1,2\]
  
**Explanation:** The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> dict;
        for( int i = 0; i<numbers.size(); i++){
            if( dict[target-numbers[i]] > 0 ){
                return {dict[target-numbers[i]], i+1};
            }
            dict[numbers[i]] = i+1;
        }
        return {};
    }
};
```
      