[41.first-missing-positive](https://leetcode.com/problems/first-missing-positive/)  

Given an unsorted integer array, find the smallest missing positive integer.

**Example 1:**

Input: \[1,2,0\]
Output: 3

**Example 2:**

Input: \[3,4,-1,1\]
Output: 2

**Example 3:**

Input: \[7,8,9,11,12\]
Output: 1

**Note:**

Your algorithm should run in _O_(_n_) time and uses constant extra space.  



**Solution:**  

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        if( N == 0 ) return 1;
        nums.push_back(nums[0]);
        N++;
        for( int i = 0; i<nums.size(); i++){
            int target = nums[i];
            while(target>= 0&&target < N && target != nums[target]){
                int new_tar = nums[target];
                nums[target] = target;
                target = new_tar;
            }
            
        }
        for( int i = 1; i<nums.size();i++){
            if( i != nums[i] )
                return i;
        }
        return N;
    }
};
```
      