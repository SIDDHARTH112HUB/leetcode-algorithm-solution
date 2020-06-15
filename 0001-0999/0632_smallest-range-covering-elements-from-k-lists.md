[632.smallest-range-covering-elements-from-k-lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)  

You have `k` lists of sorted integers in ascending order. Find the **smallest** range that includes at least one number from each of the `k` lists.

We define the range \[a,b\] is smaller than range \[c,d\] if `b-a < d-c` or `a < c` if `b-a == d-c`.

**Example 1:**

**Input:** \[\[4,10,15,24,26\], \[0,9,12,20\], \[5,18,22,30\]\]
**Output:** \[20,24\]
**Explanation:** 
List 1: \[4, 10, 15, 24,26\], 24 is in range \[20,24\].
List 2: \[0, 9, 12, 20\], 20 is in range \[20,24\].
List 3: \[5, 18, 22, 30\], 22 is in range \[20,24\].

**Note:**

1.  The given list may contain duplicates, so ascending order means >= here.
2.  1 <= `k` <= 3500
3.  \-105 <= `value of elements` <= 105.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int > > arr;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j)
                arr.push_back({nums[i][j], i});
        }
        sort(arr.begin(), arr.end());
        int e = 0, b = 0, k = 0;
        vector<int> cnt(nums.size());
        vector<int> ans;
        while(e < arr.size()) {
            if(cnt[arr[e++].second]++ == 0) ++k;
            while(k >= nums.size()) {
                int l = arr[b].first, r = arr[e- 1].first;
                if(ans.size() == 0 || r - l < ans[1] - ans[0]) {
                    ans = {l, r};
                }
                if(--cnt[arr[b++].second] == 0) --k;
            }
        }
        return ans;
    }
};
```
      