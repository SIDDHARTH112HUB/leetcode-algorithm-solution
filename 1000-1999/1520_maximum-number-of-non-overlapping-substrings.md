[1520.maximum-number-of-non-overlapping-substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)  

Given a string `s` of lowercase letters, you need to find the maximum number of **non-empty** substrings of `s` that meet the following conditions:

1.  The substrings do not overlap, that is for any two substrings `s[i..j]` and `s[k..l]`, either `j < k` or `i > l` is true.
2.  A substring that contains a certain character `c` must also contain all occurrences of `c`.

Find _the maximum number of substrings that meet the above conditions_. If there are multiple solutions with the same number of substrings, _return the one with minimum total length._ It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in **any** order.

**Example 1:**

  
**Input:** s = "adefaddaccc"  
**Output:** \["e","f","ccc"\]  
**Explanation:** The following are all the possible substrings that meet the conditions:  
\[  
  "adefaddaccc"  
  "adefadda",  
  "ef",  
  "e",  
  "f",  
  "ccc",  
\]  
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose \["e","f","ccc"\] which gives us 3 substrings. No other solution of the same number of substrings exist.  

**Example 2:**

  
**Input:** s = "abbaccd"  
**Output:** \["d","bb","cc"\]  
**Explanation:** Notice that while the set of substrings \["d","abba","cc"\] also has length 3, it's considered incorrect since it has larger total length.  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `s` contains only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> ci(26);
        for(int i = 0; i < s.size(); ++i) {
            ci[s[i] - 'a'].push_back(i);
        }
        bool ch = true;
        while(ch) {
            ch = false;
            for(int i = 0; i < ci.size(); ++i) {
                auto &v = ci[i];
                for(int j = 0; j < ci.size() && !ch; ++j){
                    auto &v2 = ci[j];
                    if(v.size() == 0 || v2.size() == 0) continue;
                    if(i == j) continue;
                    if(v[0] <= v2[0] && v.back() >= v2.back()) continue;
                    if(lower_bound(v2.begin(), v2.end(), v[0]) != lower_bound(v2.begin(), v2.end(), v.back())) {
                        if(v2[0] < v[0])
                            v.insert(v.begin(), v2[0]);
                        if(v2.back() > v.back())
                            v.push_back(v2.back());
                        ch = true;
                    }
                }
            }
        }
        vector<vector<int> > p;
        for(int i = 0; i < ci.size(); ++i) {
            auto v = ci[i];
            if(v.size()) {
                p.push_back({v.back(), v[0], i});
            }
        }
        sort(p.begin(), p.end());
        vector<string> ans;
        int prev = -1;
        for(int i = 0; i < p.size(); ++i) {
            if(prev == -1 || p[i][1] >= p[prev][0]) {
                ans.push_back(s.substr(p[i][1], p[i][0] - p[i][1] + 1));
                prev = i;
            }
        }
        return ans;
    }
};
```
      