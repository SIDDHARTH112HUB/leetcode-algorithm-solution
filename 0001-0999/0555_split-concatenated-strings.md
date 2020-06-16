[555.split-concatenated-strings](https://leetcode.com/problems/split-concatenated-strings/)  

Given a list of strings, you could concatenate these strings together into a loop, where for each string you could choose to reverse it or not. Among all the possible loops, you need to find the lexicographically biggest string after cutting the loop, which will make the looped string into a regular one.

Specifically, to find the lexicographically biggest string, you need to experience two phases:

1.  Concatenate all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
2.  Cut and make one breakpoint in any place of the loop, which will make the looped string into a regular one starting from the character at the cutpoint.

And your job is to find the lexicographically biggest one among all the possible regular strings.

**Example:**  

  
**Input:** "abc", "xyz"
  
**Output:** "zyxcba"
  
**Explanation:** You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-",   
where '-' represents the looped status.   
The answer string came from the fourth looped one,   
where you could cut from the middle character 'a' and get "zyxcba".
  

**Note:**  

1.  The input strings will only contain lowercase letters.
2.  The total length of all the strings will not over 1,000.  



**Solution:**  

```cpp
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        if (strs.empty()) return "";
        string s = "", res = "a";
        int n = strs.size(), cur = 0;
        for (string str : strs) {
            string t = string(str.rbegin(), str.rend());
            s += str > t ? str : t;
        }
        for (int i = 0; i < n; ++i) {          
            string t1 = strs[i], t2 = string(t1.rbegin(), t1.rend());
            string mid = s.substr(cur + t1.size()) + s.substr(0, cur);
            for (int j = 0; j < strs[i].size(); ++j) {
                if (t1[j] >= res[0]) res = max(res, t1.substr(j) + mid + t1.substr(0, j));
                if (t2[j] >= res[0]) res = max(res, t2.substr(j) + mid + t2.substr(0, j));
            }
            cur += strs[i].size();
        }
        return res;
    }
};
```
      