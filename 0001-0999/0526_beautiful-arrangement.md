[526.beautiful-arrangement](https://leetcode.com/problems/beautiful-arrangement/)  

Suppose you have **N** integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these **N** numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

1.  The number at the ith position is divisible by **i**.
2.  **i** is divisible by the number at the ith position.

Now given N, how many beautiful arrangements can you construct?

**Example 1:**

  
**Input:** 2
  
**Output:** 2
  
**Explanation:** 
  

  
The first beautiful arrangement is \[1, 2\]:
  

  
Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
  

  
Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
  

  
The second beautiful arrangement is \[2, 1\]:
  

  
Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
  

  
Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
  

**Note:**

1.  **N** is a positive integer and will not exceed 15.  



**Solution:**  

```cpp
class Solution {
public:
    int ans;
    int countArrangement(int N) {
        ans = 0;
        vector<int> nums;
        for( int i = 1; i<=N;i++)
            nums.push_back(i);
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int> &nums, int idx ){
        if( idx == nums.size()){
            ans++;
            return;
        }
        for( int i = 0; i<nums.size(); i++){
            if( nums[i] == 0 )
                continue;
            if( nums[i] % (idx+1) == 0 || (idx+1)%nums[i] == 0 ){
                int src = nums[i];
                nums[i] = 0;
                dfs(nums, idx+1);
                nums[i] = src;
            }
        }
    }
};
```
      