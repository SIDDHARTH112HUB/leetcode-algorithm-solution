[1151.minimum-swaps-to-group-all-1s-together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)  

Given a binary array `data`, return the minimum number of swaps required to group all `1`’s present in the array together in **any place** in the array.

**Example 1:**

  
**Input:** \[1,0,1,0,1\]  
**Output:** 1  
**Explanation: **  
There are 3 ways to group all 1's together:  
\[1,1,1,0,0\] using 1 swap.  
\[0,1,1,1,0\] using 2 swaps.  
\[0,0,1,1,1\] using 1 swap.  
The minimum is 1.  

**Example 2:**

  
**Input:** \[0,0,0,1,0\]  
**Output:** 0  
**Explanation: **  
Since there is only one 1 in the array, no swaps needed.  

**Example 3:**

  
**Input:** \[1,0,1,0,1,0,0,1,1,0,1\]  
**Output:** 3  
**Explanation: **  
One possible solution that uses 3 swaps is \[0,0,0,0,0,1,1,1,1,1,1\].  

**Note****:**

1.  `1 <= data.length <= 10^5`
2.  `0 <= data[i] <= 1`  



**Solution:**  

```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total = 0;
        int ans = INT_MAX;
        for(int i = 0; i < data.size(); ++i){
            total += data[i];
            if(i > 0)
                data[i] += data[i-1];
        }
        if( total <= 1) return 0;
        for(int i = 0; i < data.size(); ++i) {
            if(i >= total - 1) {
                ans = min(ans, total - data[i] + (i >= total ? data[i-total] : 0));
            }
        }
        return ans;
    }
};
```
      