[1574.shortest-subarray-to-be-removed-to-make-array-sorted](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)  

Given an integer array `arr`, remove a subarray (can be empty) from `arr` such that the remaining elements in `arr` are **non-decreasing**.

A subarray is a contiguous subsequence of the array.

Return _the length of the shortest subarray to remove_.

**Example 1:**

  
**Input:** arr = \[1,2,3,10,4,2,3,5\]  
**Output:** 3  
**Explanation:** The shortest subarray we can remove is \[10,4,2\] of length 3. The remaining elements after that will be \[1,2,3,3,5\] which are sorted.  
Another correct solution is to remove the subarray \[3,10,4\].

**Example 2:**

  
**Input:** arr = \[5,4,3,2,1\]  
**Output:** 4  
**Explanation:** Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either \[5,4,3,2\] or \[4,3,2,1\].  

**Example 3:**

  
**Input:** arr = \[1,2,3\]  
**Output:** 0  
**Explanation:** The array is already non-decreasing. We do not need to remove any elements.  

**Example 4:**

  
**Input:** arr = \[1\]  
**Output:** 0  

**Constraints:**

*   `1 <= arr.length <= 10^5`
*   `0 <= arr[i] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int ans = 0;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] >= arr[i - 1]) l = i;
            else break;
        }
        for(int i = arr.size() - 1; i > 0; --i) {
            if(arr[i] >= arr[i - 1]) r = i - 1;
            else break;
        }
        if(l == arr.size() - 1) return 0;
        ans = max(max(ans, l + 1), (int)arr.size() - r);
        vector<int> lv, rv;
        for(int i = 0; i <= l; ++i) {
            lv.push_back(arr[i]);
            // cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i = r; i < arr.size(); ++i) {
            // cout<<arr[i]<<" "; 
            int n = arr[i];
            int lc = upper_bound(lv.begin(), lv.end(), n) - lv.begin();
            ans = max(ans, lc + (int)arr.size() - i);
            // cout<<"ans:"<<ans<<endl;
        }
        // cout<<endl;
        return arr.size() - ans;
    }
};
```
      