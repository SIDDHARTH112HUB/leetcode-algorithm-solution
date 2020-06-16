[1417.reformat-the-string](https://leetcode.com/problems/reformat-the-string/)  

Given alphanumeric string `s`. (**Alphanumeric string** is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return _the reformatted string_ or return **an empty string** if it is impossible to reformat the string.

**Example 1:**

  
**Input:** s = "a0b1c2"  
**Output:** "0a1b2c"  
**Explanation:** No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.  

**Example 2:**

  
**Input:** s = "leetcode"  
**Output:** ""  
**Explanation:** "leetcode" has only characters so we cannot separate them by digits.  

**Example 3:**

  
**Input:** s = "1229857369"  
**Output:** ""  
**Explanation:** "1229857369" has only digits so we cannot separate them by characters.  

**Example 4:**

  
**Input:** s = "covid2019"  
**Output:** "c2o0v1i9d"  

**Example 5:**

  
**Input:** s = "ab123"  
**Output:** "1a2b3"  

**Constraints:**

*   `1 <= s.length <= 500`
*   `s` consists of only lowercase English letters and/or digits.  



**Solution:**  

```cpp
class Solution {
public:
    string reformat(string s) {
        string l, d;
        for(auto c : s) {
            if(c>='0' && c<='9')
                d+= c;
            else
                l += c;
        }
        string ans;
        if(abs(int(l.size()) - int(d.size())) > 1)
            return "";
        string s1, s2;
        if(l.size() > d.size()) {
            s1 = l;
            s2 = d;
        }else{
            s1 = d;
            s2 = l;
        }
        while(s1.size()) {
            ans += s1.back();
            s1.pop_back();
            if(s2.size()){
                ans += s2.back();
                s2.pop_back();
            }
        }
        return ans;
    }
};
```
      