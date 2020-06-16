[442.find-all-duplicates-in-an-array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)  

Given an array of integers, 1 ≤ a\[i\] ≤ _n_ (_n_ = size of array), some elements appear **twice** and others appear **once**.

Find all the elements that appear **twice** in this array.

Could you do it without extra space and in O(_n_) runtime?

**Example:**  

  
**Input:**
  
\[4,3,2,7,8,2,3,1\]
  

  
**Output:**
  
\[2,3\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans;
        if( N == 0 ) return ans;
        nums.push_back(nums[0]);
        nums[0] = 0;
        N++;
        for( int i = 1; i<N; i++ ){
            while( nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for( int i = 1; i<N; i++ ){
            if( nums[i] != i )
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
```
      