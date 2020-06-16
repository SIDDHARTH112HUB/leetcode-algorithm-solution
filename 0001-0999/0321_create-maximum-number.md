[321.create-maximum-number](https://leetcode.com/problems/create-maximum-number/)  

Given two arrays of length `m` and `n` with digits `0-9` representing two numbers. Create the maximum number of length `k <= m + n` from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the `k` digits.

**Note:** You should try to optimize your time and space complexity.

**Example 1:**

  
**Input:**
  
nums1 = `[3, 4, 6, 5]`
  
nums2 = `[9, 1, 2, 5, 8, 3]`
  
k = `5`
  
**Output:**
  
`[9, 8, 6, 5, 3]`

**Example 2:**

  
**Input:**
  
nums1 = `[6, 7]`
  
nums2 = `[6, 0, 4]`
  
k = `5`
  
**Output:**
  
`[6, 7, 6, 0, 4]`

**Example 3:**

  
**Input:**
  
nums1 = `[3, 9]`
  
nums2 = `[8, 9]`
  
k = `3`
  
**Output:**
  
`[9, 8, 9]`  



**Solution:**  

```cpp
class Solution {
public:
    
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(ans.size() == 0){
                ans.push_back(n);
                continue;
            }
            while(ans.size() && nums.size() - i + ans.size() > k && ans.back() < n){
                ans.pop_back();
            }
            ans.push_back(n);
        }
        while(ans.size() > k)
            ans.pop_back();
        return ans;
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        auto b1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto b2 = nums2.cbegin();
        auto e2 = nums2.cend();
        vector<int> ans;
        while(b1 != e1 || b2 != e2) {
            bool res = lexicographical_compare(b1, e1, b2, e2);
            ans.push_back(res ? *b2++ : *b1++);
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i = 0; i <=k; ++i){
            if( i > nums1.size() || k - i > nums2.size())continue;
            auto a1 = maxArray(nums1, i);
            auto a2 = maxArray(nums2, k-i);
            ans = max(ans, merge(a1, a2) );
        }
        return ans;
    }
};
```
      