[219.contains-duplicate-ii](https://leetcode.com/problems/contains-duplicate-ii/)  

Given an array of integers and an integer _k_, find out whether there are two distinct indices _i_ and _j_ in the array such that **nums\[i\] = nums\[j\]** and the **absolute** difference between _i_ and _j_ is at most _k_.

**Example 1:**

**Input:** nums = \[1,2,3,1\], k = 3
**Output:** true

**Example 2:**

**Input:** nums = \[1,0,1,1\], k = 1
**Output:** true

**Example 3:**

**Input:** nums = \[1,2,3,1,2,3\], k = 2
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, set<int> > m;
        for(int i = 0; i < nums.size(); ++i){
            int n =  nums[i];
            
            if(m[n].size() > 0){
                if(i - k <= 0)
                    return true;
                auto it = m[n].lower_bound(abs(i - k));
                if(it != m[n].end())
                    return true;
                if(it == m[n].begin() && *it >= abs(i-k))
                    return true;
            }
            m[n].insert(i);
        }
        return false;
    }
};
```
      