[491.increasing-subsequences](https://leetcode.com/problems/increasing-subsequences/)  

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

**Example:**

  
**Input:** \[4, 6, 7, 7\]  
**Output:** \[\[4, 6\], \[4, 7\], \[4, 6, 7\], \[4, 6, 7, 7\], \[6, 7\], \[6, 7, 7\], \[7,7\], \[4,7,7\]\]  

**Constraints:**

*   The length of the given array will not exceed 15.
*   The range of integer in the given array is \[-100,100\].
*   The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.  



**Solution:**  

```cpp
class Solution {
public:
    set<vector<int> > ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> arr;
        f(nums, 0, arr);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void f(vector<int> &nums, int idx, vector<int> &arr) {
        if(idx >= nums.size() ){
            if(arr.size() >= 2)
                ans.insert(arr);
            return;
        }
        if((arr.size() == 0 || arr.back() <= nums[idx])) {
            arr.push_back(nums[idx]);
            f(nums, idx+1, arr);
            arr.pop_back();
        }
        f(nums, idx + 1, arr);
        
    }
};
```
      