[611.valid-triangle-number](https://leetcode.com/problems/valid-triangle-number/)  

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

**Example 1:**  

**Input:** \[2,2,3,4\]
**Output:** 3
**Explanation:**
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

**Note:**  

1.  The length of the given array won't exceed 1000.
2.  The integers in the given array are in the range of \[0, 1000\].  



**Solution:**  

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = 0;
        if( size < 3 ) return 0;
        for( int i = size-1; i>1; i--){
            //int j = i+1, k = size-1;
            int a = nums[i];
            int k = 0, j = i-1;
            while(k<j){
                if( nums[j] + nums[k] > a){
                    ans += (j--)-k;
                }else
                    k++;
            }
        }
        return ans;
    }
};
```
      