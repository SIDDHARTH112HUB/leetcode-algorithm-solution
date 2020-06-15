[1109.corporate-flight-bookings](https://leetcode.com/problems/corporate-flight-bookings/)  

There are `n` flights, and they are labeled from `1` to `n`.

We have a list of flight bookings.  The `i`\-th booking `bookings[i] = [i, j, k]` means that we booked `k` seats from flights labeled `i` to `j` inclusive.

Return an array `answer` of length `n`, representing the number of seats booked on each flight in order of their label.

**Example 1:**

**Input:** bookings = \[\[1,2,10\],\[2,3,20\],\[2,5,25\]\], n = 5
**Output:** \[10,55,45,25,25\]

**Constraints:**

*   `1 <= bookings.length <= 20000`
*   `1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000`
*   `1 <= bookings[i][2] <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<pair<int, int> > m(n+1);
        for(auto &book : bookings) {
            int i = book[0];
            int j = book[1];
            int s = book[2];
            m[i].first += s;
            m[j].second += s;
        }
        vector<int> ans(n);
        long long total = 0;
        for(int i = 1; i <= n; ++i) {
            int b = m[i].first;
            int e = m[i].second;
            total += b;
            //total += e;
            ans[i-1] += total;
            total -= e;
        }
        return ans;
    }
};
```
      