[220.contains-duplicate-iii](https://leetcode.com/problems/contains-duplicate-iii/)  

Given an array of integers, find out whether there are two distinct indices _i_ and _j_ in the array such that the **absolute** difference between **nums\[i\]** and **nums\[j\]** is at most _t_ and the **absolute** difference between _i_ and _j_ is at most _k_.

**Example 1:**

**Input:** nums = \[1,2,3,1\], k = 3, t = 0
**Output:** true

**Example 2:**

**Input:** nums = \[1,0,1,1\], k = 1, t = 2
**Output:** true

**Example 3:**

**Input:** nums = \[1,5,9,1,5,9\], k = 2, t = 3
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if( nums.size() <= 1 ) return false;
        map<long long, int> m;
        int j = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( i - j > k) m.erase(nums[j++]);
            auto it = m.lower_bound((long long)(nums[i]) - t);
            if( it != m.end() && abs(it->first - nums[i] )<=t  )
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
```
      