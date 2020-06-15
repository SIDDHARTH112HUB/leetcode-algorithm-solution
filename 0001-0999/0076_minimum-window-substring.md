[76.minimum-window-substring](https://leetcode.com/problems/minimum-window-substring/)  

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

**Input: S** = "ADOBECODEBANC", **T** = "ABC"
**Output:** "BANC"

**Note:**

*   If there is no such window in S that covers all characters in T, return the empty string `""`.
*   If there is such window, you are guaranteed that there will always be only one unique minimum window in S.  



**Solution:**  

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int end = 0, begin = 0, counter = 0, size = s.size();
        unordered_map<int, int> hash;
        pair<int, int> ans = {0, 100000000};
        for( char c :t) ++hash[c];
        counter = hash.size();
        while(end < size ) {
            if( hash[s[end++]]-- == 1 ) counter--;
            while(counter == 0 &&  begin < end ){
                if( end - begin < ans.second - ans.first ) ans={begin, end};
                if(hash[s[begin++]]++ >= 0) counter++;
            }
        }
        return ans.second-ans.first>size ? "" : s.substr(ans.first, ans.second-ans.first);
    }
};
```
      