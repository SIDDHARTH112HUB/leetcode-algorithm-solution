[1124.longest-well-performing-interval](https://leetcode.com/problems/longest-well-performing-interval/)  

We are given `hours`, a list of the number of hours worked per day for a given employee.

A day is considered to be a _tiring day_ if and only if the number of hours worked is (strictly) greater than `8`.

A _well-performing interval_ is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

**Example 1:**

  
**Input:** hours = \[9,9,6,0,6,6,9\]  
**Output:** 3  
**Explanation:** The longest well-performing interval is \[9,9,6\].  

**Constraints:**

*   `1 <= hours.length <= 10000`
*   `0 <= hours[i] <= 16`  



**Solution:**  

```cpp
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        for(int &h : hours)
            h = h > 8 ? 1 : -1;
        for(int i = 0; i < hours.size(); ++i){
            int cnt = 0;
            for(int j = i; j < hours.size(); ++j){
                cnt += hours[j];
                if(cnt > 0)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```
      