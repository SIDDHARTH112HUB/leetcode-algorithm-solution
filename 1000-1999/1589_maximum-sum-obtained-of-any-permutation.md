[1589.maximum-sum-obtained-of-any-permutation](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/)  

We have an array of integers, `nums`, and an array of `requests` where `requests[i] = [starti, endi]`. The `ith` request asks for the sum of `nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]`. Both `starti` and `endi` are _0-indexed_.

Return _the maximum total sum of all requests **among all permutations** of_ `nums`.

Since the answer may be too large, return it **modulo** `109 + 7`.

**Example 1:**

  
**Input:** nums = \[1,2,3,4,5\], requests = \[\[1,3\],\[0,1\]\]  
**Output:** 19  
**Explanation:** One permutation of nums is \[2,1,3,4,5\] with the following result:   
requests\[0\] -> nums\[1\] + nums\[2\] + nums\[3\] = 1 + 3 + 4 = 8  
requests\[1\] -> nums\[0\] + nums\[1\] = 2 + 1 = 3  
Total sum: 8 + 3 = 11.  
A permutation with a higher total sum is \[3,5,4,2,1\] with the following result:  
requests\[0\] -> nums\[1\] + nums\[2\] + nums\[3\] = 5 + 4 + 2 = 11  
requests\[1\] -> nums\[0\] + nums\[1\] = 3 + 5  = 8  
Total sum: 11 + 8 = 19, which is the best that you can do.  

**Example 2:**

  
**Input:** nums = \[1,2,3,4,5,6\], requests = \[\[0,1\]\]  
**Output:** 11  
**Explanation:** A permutation with the max total sum is \[6,5,4,3,2,1\] with request sums \[11\].

**Example 3:**

  
**Input:** nums = \[1,2,3,4,5,10\], requests = \[\[0,2\],\[1,3\],\[1,1\]\]  
**Output:** 47  
**Explanation:** A permutation with the max total sum is \[4,10,5,3,2,1\] with request sums \[19,18,10\].

**Constraints:**

*   `n == nums.length`
*   `1 <= n <= 105`
*   `0 <= nums[i] <= 105`
*   `1 <= requests.length <= 105`
*   `requests[i].length == 2`
*   `0 <= starti <= endi < n`  



**Solution:**  

```cpp
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long long M = 1e9+7;
        map<int, int> cnt;
        sort(requests.begin(), requests.end(), [](auto &a, auto &b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        vector<int> arr(nums.size());
        for(auto &r: requests) {
            ++cnt[r[0]];
            --cnt[r[1]+1];
        }
        cnt[arr.size()] = 0;
        int prev = 0, prevCnt = 0, c = 0;
        for(auto it : cnt) {
            c += it.second;
            for(int i = prev; i < it.first; ++i) {
                arr[i] = prevCnt;
            }
            prev = it.first; prevCnt= c;
            if(it.first >= arr.size()) break;
        }
        sort(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] <= 0) continue;
            ans += arr[i] * nums[i];
            ans %= M;
        }
        return ans;
    }
};
```
      