[1234.replace-the-substring-for-balanced-string](https://leetcode.com/problems/replace-the-substring-for-balanced-string/)  

You are given a string containing only 4 kinds of characters `'Q',` `'W', 'E'` and `'R'`.

A string is said to be **balanced** if each of its characters appears `n/4` times where `n` is the length of the string.

Return the minimum length of the substring that can be replaced with **any** other string of the same length to make the original string `s` **balanced**.

Return 0 if the string is already **balanced**.

**Example 1:**

**Input:** s = "QWER"
**Output:** 0
**Explanation:** s is already balanced.

**Example 2:**

**Input:** s = "QQWE"
**Output:** 1
**Explanation:** We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

**Example 3:**

**Input:** s = "QQQW"
**Output:** 2
**Explanation:** We can replace the first "QQ" to "ER". 

**Example 4:**

**Input:** s = "QQQQ"
**Output:** 3
**Explanation:** We can replace the last 3 'Q' to make s = "QWER".

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `s.length` is a multiple of `4`
*   `s` contains only `'Q'`, `'W'`, `'E'` and `'R'`.  



**Solution:**  

```cpp
class Solution {
public:
    bool check(vector<int> &cnt) {
        for(auto n : cnt){
            if(n > 0)
                return false;
        }
        return true;
    }
    int balancedString(string s) {
        int n = s.size() / 4;
        vector<char> v = {'Q', 'R', 'E', 'W'};
        unordered_map<int, int> m;
        vector<int> cnt(128);
        for(auto c : s) {
            ++m[c];
        }
        for(auto c : v) {
            if(m[c] > n){
                cnt[c] = m[c] - n;
                //cout<<c<<" "<<cnt[c]<<endl;
            }
        }
        if(check(cnt)) return 0;
        int ans = INT_MAX;
        int j = 0;
        int tmp = 0;
        int res = INT_MAX;
        for(int i = 0; i < s.size(); ++i) {
            //cout<<cnt[s[i]]<<endl;
            --cnt[s[i]];
            bool f = check(cnt);
            
            if(!f) continue;
            while(check(cnt)) {
                ++cnt[s[j++]];
            }
            //cout<<"i :"<<i<<" j:"<<j<<endl;
            res = min(res, i - j + 2);
        }
        return res;
    }
};
```
      