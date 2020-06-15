[358.rearrange-string-k-distance-apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/)  

Given a non-empty string **s** and an integer **k**, rearrange the string such that the same characters are at least distance **k** from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string `""`.

**Example 1:**

**Input:** s = "aabbcc", k = 3
**Output:** "abcabc" 
**Explanation:** The same letters are at least distance 3 from each other.

**Example 2:**

**Input:** s = "aaabc", k = 3
**Output:** "" 
**Explanation:** It is not possible to rearrange the string.

**Example 3:**

**Input:** s = "aaadbbcc", k = 2
**Output:** "abacabcd" **Explanation:** The same letters are at least distance 2 from each other.  



**Solution:**  

```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        map<int, int> m;
        for(auto c : s)
            ++m[c];
        priority_queue<pair<int, int> > pq;
        for(auto it : m) {
            pq.push({it.second, it.first});
        }
        string ans;
        while(pq.size()) {
            if((int)pq.size() < min(k, (int)s.size() - (int)ans.size()))return "";
            vector< pair<int, int> > t;
            int cnt = k;
            while(pq.size() && cnt-- > 0) {
                t.push_back(pq.top()); pq.pop();
            }
            for(auto &p : t) {
                ans += p.second; --p.first;
                if(p.first > 0)
                    pq.push(p);
            }
        }
        return ans;
    }
};
```
      