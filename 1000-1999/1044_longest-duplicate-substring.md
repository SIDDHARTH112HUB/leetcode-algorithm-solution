[1044.longest-duplicate-substring](https://leetcode.com/problems/longest-duplicate-substring/)  

Given a string `S`, consider all _duplicated substrings_: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return **any** duplicated substring that has the longest possible length.  (If `S` does not have a duplicated substring, the answer is `""`.)

**Example 1:**

  
**Input:** "banana"
  
**Output:** "ana"
  

**Example 2:**

  
**Input:** "abcd"
  
**Output:** ""
  

**Note:**

1.  `2 <= S.length <= 10^5`
2.  `S` consists of lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int test(string &s, int l) {
        unsigned long long m = 1000000007;
        unsigned long long p = 1;
        unsigned long long cur = 0;
        for(int i = 0; i < l; ++i) {
            p =  (p * 26);
            cur = (cur * 26 + s[i] - 'a');
        }
        unordered_map<unsigned long long, vector<int> > st;
        st[cur].push_back(0);
        for(int i = 0; i < s.size() - l; ++i) {
            cur = ((cur * 26) + s[l+i] - 'a' - (s[i] - 'a')*p);
            if(st.count(cur)){
                for(auto idx : st[cur]) 
                    if (s.substr(idx, l) == s.substr( i+1, l))
                        return i + 1;
            }
            st[cur].push_back(i+1);
        }
        return -1;
    }
    string longestDupSubstring(string S) {
        int l = 0, r = S.size();
        string ans;
        while (l < r) {
            int mid = (l+r) / 2;
            int idx = test(S, mid);
            if(idx >= 0){
                l = mid + 1;
                ans = S.substr(idx, mid);
            }else
                r = mid;
        }
        return ans;
    }
};
```
      