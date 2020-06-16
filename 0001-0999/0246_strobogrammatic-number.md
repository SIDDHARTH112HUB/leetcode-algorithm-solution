[246.strobogrammatic-number](https://leetcode.com/problems/strobogrammatic-number/)  

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

**Example 1:**

  
**Input:**  "69"
  
**Output:** true
  

**Example 2:**

  
**Input:**  "88"
  
**Output:** true

**Example 3:**

  
**Input:**  "962"
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<int, int> m;
        m['0'] = '0';
        m['1'] = '1';
        m['2'] = 2;
        m['3'] = 3;
        m['4'] = 4;
        m['5'] = 5;
        m['6'] = '9';
        m['7'] = 7;
        m['8'] = '8';
        m['9'] = '6';
        string ans;
        for(int i = 0; i < num.size(); ++i) {
            ans += m[num[i]];
        }
        reverse(ans.begin(), ans.end());
        return ans == num;
    }
};
```
      