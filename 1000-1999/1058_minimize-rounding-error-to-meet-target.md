[1058.minimize-rounding-error-to-meet-target](https://leetcode.com/problems/minimize-rounding-error-to-meet-target/)  

Given an array of prices `[p1,p2...,pn]` and a `target`, round each price `pi` to `Roundi(pi)` so that the rounded array `[Round1(p1),Round2(p2)...,Roundn(pn)]` sums to the given `target`. Each operation `Roundi(pi)` could be either `Floor(pi)` or `Ceil(pi)`.

Return the string `"-1"` if the rounded array is impossible to sum to `target`. Otherwise, return the smallest rounding error, which is defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, as a string with three places after the decimal.

**Example 1:**

**Input:** prices = \["0.700","2.800","4.900"\], target = 8
**Output:** "1.000"
**Explanation:** 
Use Floor, Ceil and Ceil operations to get (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 .

**Example 2:**

**Input:** prices = \["1.500","2.500","3.500"\], target = 10
**Output:** "-1"
**Explanation:** 
It is impossible to meet the target.

**Note:**

1.  `1 <= prices.length <= 500`.
2.  Each string of prices `prices[i]` represents a real number which is between 0 and 1000 and has exactly 3 decimal places.
3.  `target` is between 0 and 1000000.  



**Solution:**  

```cpp
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        map<int, float> dp;
        dp[0] = 0;
        for(int i = 0; i < prices.size(); ++i) {
            map<int, float> tmp;
            float price = stod(prices[i]);
            for(auto &it : dp) {
                int cur = it.first + floor(price);
                float diff = it.second + fabs(price - floor(price));
                if(cur <= target && (tmp.count(cur) == 0 || diff < tmp[cur])) {
                    tmp[cur] = diff;
                }
                cur = it.first + ceil(price);
                diff = it.second + fabs(price - ceil(price));
                if(cur <= target && (tmp.count(cur) == 0 || diff < tmp[cur])) {
                    tmp[cur] = diff;
                }
            }
            dp = tmp;
        }
        if(dp.count(target) == 0) return "-1";
        stringstream stream;
        stream << fixed << setprecision(3) << dp[target];
        string s = stream.str();
        return s;
    }
};
```
      