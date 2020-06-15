[67.add-binary](https://leetcode.com/problems/add-binary/)  

Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

**Example 1:**

**Input:** a = "11", b = "1"
**Output:** "100"

**Example 2:**

**Input:** a = "1010", b = "1011"
**Output:** "10101"

**Constraints:**

*   Each string consists only of `'0'` or `'1'` characters.
*   `1 <= a.length, b.length <= 10^4`
*   Each string is either `"0"` or doesn't contain any leading zero.  



**Solution:**  

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int endA = a.size()-1;
        int endB = b.size()-1;
        string ans;
        int carry  = 0;
        while( endA>=0 || endB >=0){
            int sum = (endA>=0?a[endA--] -'0':0) + (endB>=0?b[endB--]-'0':0) + carry;
            carry = sum /2;
            ans+= sum%2>0?'1':'0';
        }
        if( carry > 0 )
            ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      