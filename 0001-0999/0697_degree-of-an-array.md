[697.degree-of-an-array](https://leetcode.com/problems/degree-of-an-array/)  

Given a non-empty array of non-negative integers `nums`, the **degree** of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of `nums`, that has the same degree as `nums`.

**Example 1:**  

**Input:** \[1, 2, 2, 3, 1\]
**Output:** 2
**Explanation:** 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
\[1, 2, 2, 3, 1\], \[1, 2, 2, 3\], \[2, 2, 3, 1\], \[1, 2, 2\], \[2, 2, 3\], \[2, 2\]
The shortest length is 2. So return 2.

**Example 2:**  

**Input:** \[1,2,2,3,1,4,2\]
**Output:** 6

**Note:**

*   `nums.length` will be between 1 and 50,000.
*   `nums[i]` will be an integer between 0 and 49,999.  



**Solution:**  

```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int> > pos;
        int len = 0, ans=INT_MAX;
        for( int i = 0; i < nums.size(); i++ ){
            int n = nums[i];
            if( ++m[n] ==1 ){
                pos[n] = {i, i};
            }else
                pos[n].second = i;
            len = max(len, m[n]);
        }
        for( auto it : m ){
            if( it.second == len ){
                ans = min( ans, pos[it.first].second - pos[it.first].first + 1);
            }
        }
        return ans;
        /*
        int left = 0, right = nums.size() - 1;
        while(left <= right ){
            right = nums.size() - 1;
            while(left < nums.size() && m[nums[left]] != len ) left++;
            while(left < nums.size() && right >=0 && nums[right] != nums[left] ) right--;
            if( left <= right ){
                ans = min(ans, right-left+1);
                m[nums[left]] = -1;
            }
            
        }
        return ans;*/
    }
};
```
      