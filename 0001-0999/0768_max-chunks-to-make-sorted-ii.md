[768.max-chunks-to-make-sorted-ii](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)  

_This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length `2000`, and the elements could be up to `10**8`._

* * *

Given an array `arr` of integers (**not necessarily distinct**), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

**Example 1:**

  
**Input:** arr = \[5,4,3,2,1\]
  
**Output:** 1
  
**Explanation:**
  
Splitting into two or more chunks will not return the required result.
  
For example, splitting into \[5, 4\], \[3, 2, 1\] will result in \[4, 5, 1, 2, 3\], which isn't sorted.
  

**Example 2:**

  
**Input:** arr = \[2,1,3,4,4\]
  
**Output:** 4
  
**Explanation:**
  
We can split into two chunks, such as \[2, 1\], \[3, 4, 4\].
  
However, splitting into \[2, 1\], \[3\], \[4\], \[4\] is the highest number of chunks possible.
  

**Note:**

*   `arr` will have length in range `[1, 2000]`.
*   `arr[i]` will be an integer in range `[0, 10**8]`.  



**Solution:**  

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int, int> > arr2;
        for(int i = 0; i < arr.size(); ++i) {
            arr2.push_back({arr[i], i});
        }
        sort(arr2.begin(), arr2.end());
        int mx = 0, ans = 0;
        for(int i = 0; i < arr2.size(); ++i) {
            mx = max(arr2[i].second, mx);
            if(mx == i)
                ++ans;
        }
        return ans;
    }
};
```
      