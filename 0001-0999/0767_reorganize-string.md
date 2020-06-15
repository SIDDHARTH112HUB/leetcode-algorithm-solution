[767.reorganize-string](https://leetcode.com/problems/reorganize-string/)  

Given a string `S`, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

**Example 1:**

**Input:** S = "aab"
**Output:** "aba"

**Example 2:**

**Input:** S = "aaab"
**Output:** ""

**Note:**

*   `S` will consist of lowercase letters and have length in range `[1, 500]`.  



**Solution:**  

```cpp
class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, int> > pq;
        vector<int> cnt(128);
        for(char c : S) {
            ++cnt[c];
            if(cnt[c] > (S.size() + 1) /2  + 1) return "";
        }
        for(int i = 0; i < cnt.size(); ++i) {
            if(cnt[i] > 0)
                pq.push({cnt[i], i});
        }
        string ans = "";
        while(pq.size()) {
            if(pq.size() == 1) {
                if(pq.top().first > 1) return "";
                if(pq.top().first == 1)
                    ans += pq.top().second;
                return ans;
            }
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            --p1.first;
            --p2.first;
            if(p1.first > 0)
                pq.push(p1);
            if(p2.first > 0)
                pq.push(p2);
        }
        return ans;
    }
};
```
      