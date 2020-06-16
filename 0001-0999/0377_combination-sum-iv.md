[377.combination-sum-iv](https://leetcode.com/problems/combination-sum-iv/)  

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

**Example:**

  
_**nums**_ = \[1, 2, 3\]
  
_**target**_ = 4
  

  
The possible combination ways are:
  
(1, 1, 1, 1)
  
(1, 1, 2)
  
(1, 2, 1)
  
(1, 3)
  
(2, 1, 1)
  
(2, 2)
  
(3, 1)
  

  
Note that different sequences are counted as different combinations.
  

  
Therefore the output is _**7**_.
  

**Follow up:**  
What if negative numbers are allowed in the given array?  
How does it change the problem?  
What limitation we need to add to the question to allow negative numbers?

**Credits:**  
Special thanks to [@pbrother](https://leetcode.com/pbrother/) for adding this problem and creating all test cases.  



**Solution:**  

```cpp
class Solution {
public:
    
    map<int, int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        
        if( target < 0 || nums.size() == 0 ) return 0;
        if( target == 0 ) return 1;
        auto it = dp.find(target);
        if( it != dp.end() ) return it->second; 
        int cnt = 0;
        
        for( int n: nums){
            cnt += combinationSum4(nums, target - n);
        }
        dp[target] = cnt;
        return cnt;
    }
};
```
      