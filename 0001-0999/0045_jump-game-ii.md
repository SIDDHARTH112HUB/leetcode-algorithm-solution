[45.jump-game-ii](https://leetcode.com/problems/jump-game-ii/)  

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example:**

  
**Input:** \[2,3,1,1,4\]
  
**Output:** 2
  
**Explanation:** The minimum number of jumps to reach the last index is 2.
  
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

**Note:**

You can assume that you can always reach the last index.  



**Solution:**  

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if( nums.size() <= 1 ) return 0;
        int i = 0;
        int ans = 0;
        while( i < nums.size() -1){
            if( i + nums[i] >= nums.size() -1 )
                return ans+1;
            int maxStep = 0;
            int j = nums[i] + i;
            int cur = i;
            while( j > cur){
                if( maxStep < j + nums[j] ){
                    maxStep = j + nums[j];
                    i = j;
                }
                j--;
            }
            ans++;
        }
        return ans;
    }
};
```
      