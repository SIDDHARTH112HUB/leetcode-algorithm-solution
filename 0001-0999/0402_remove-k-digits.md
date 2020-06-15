[402.remove-k-digits](https://leetcode.com/problems/remove-k-digits/)  

Given a non-negative integer _num_ represented as a string, remove _k_ digits from the number so that the new number is the smallest possible.

**Note:**  

*   The length of _num_ is less than 10002 and will be ≥ _k_.
*   The given _num_ does not contain any leading zero.

**Example 1:**

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

**Example 2:**

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

**Example 3:**

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.  



**Solution:**  

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(auto c : num) {
            while(ans.size() && ans.back() > c && k > 0) {
                ans.pop_back();
                --k;
            }
            if(c > '0' || ans.size() > 0)
                ans += c;
        }
        while(ans.size() && k-- > 0)
            ans.pop_back();
        return ans == "" ? "0" : ans;
    }
};
```
      