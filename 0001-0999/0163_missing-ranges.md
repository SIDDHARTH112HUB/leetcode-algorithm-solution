[163.missing-ranges](https://leetcode.com/problems/missing-ranges/)  

Given a sorted integer array **_nums_**, where the range of elements are in the **inclusive range** **\[_lower_, _upper_\]**, return its missing ranges.

**Example:**

  
**Input:** **_nums_** = `[0, 1, 3, 50, 75]`, **_lower_** = 0 and **_upper_** = 99,
  
**Output:** `["2", "4->49", "51->74", "76->99"]`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& _nums, long long lower, long long upper) {
        //if(lower == upper) return {to_string(lower)};
        vector<long long> nums;
        for(auto n : _nums)
            nums.push_back(n);
        vector<string> ans;
        auto it = upper_bound(nums.begin(), nums.end(), lower-1);
        nums.insert(it, lower-1);
        it = upper_bound(nums.begin(), nums.end(), upper);
        nums.insert(it, upper + 1);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < lower) continue;
            if(nums[i] > upper + 1) continue;
            long long l = nums[i - 1], r = nums[i];
            if(r - l > 1) {
                ans.push_back(to_string(l + 1) + (r - l > 2 ? ("->" + to_string(r - 1)) :""));
            }
        }
        return ans;
    }
};
```
      