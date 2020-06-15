[1108.defanging-an-ip-address](https://leetcode.com/problems/defanging-an-ip-address/)  

Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A _defanged IP address_ replaces every period `"."` with `"[.]"`.

**Example 1:**

**Input:** address = "1.1.1.1"
**Output:** "1\[.\]1\[.\]1\[.\]1"

**Example 2:**

**Input:** address = "255.100.50.0"
**Output:** "255\[.\]100\[.\]50\[.\]0"

**Constraints:**

*   The given `address` is a valid IPv4 address.  



**Solution:**  

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto c : address) {
            if( c == '.') {
                ans.push_back('[');
                ans.push_back(c);
                ans.push_back(']');
            }else
                ans.push_back(c);
        }
        return ans;
    }
};
```
      