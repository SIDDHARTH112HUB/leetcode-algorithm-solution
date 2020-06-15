[1481.least-number-of-unique-integers-after-k-removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)  

      Given an array of integers `arr` and an integer `k`. Find the _least number of unique integers_ after removing **exactly** `k` elements**.**

**Example 1:**

**Input:** arr = \[5,5,4\], k = 1
**Output:** 1
**Explanation**: Remove the single 4, only 5 is left.

**Example 2:**

**Input:** arr = \[4,3,1,1,3,3,2\], k = 3
**Output:** 2
**Explanation**: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

**Constraints:**

*   `1 <= arr.length <= 10^5`
*   `1 <= arr[i] <= 10^9`
*   `0 <= k <= arr.length`  



**Solution:**  

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        for(auto n : arr) {
            ++m[n];
        }
        vector<pair<int, int> > cnt;
        for(auto it : m) {
            cnt.push_back({it.second, it.first});
        }
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < cnt.size(); ++i) {
            if(k >= cnt[i].first) {
                k -= cnt[i].first;
            }else {
                return cnt.size() - i;
            }
        }
        return 0;
    }
};
```
      