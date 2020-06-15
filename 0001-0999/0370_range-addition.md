[370.range-addition](https://leetcode.com/problems/range-addition/)  

Assume you have an array of length **_n_** initialized with all **0**'s and are given **_k_** update operations.

Each operation is represented as a triplet: **\[startIndex, endIndex, inc\]** which increments each element of subarray **A\[startIndex ... endIndex\]** (startIndex and endIndex inclusive) with **inc**.

Return the modified array after all **_k_** operations were executed.

**Example:**

**Input:** length = 5, updates = \[\[1,3,2\],\[2,4,3\],\[0,2,-2\]\]
**Output:** \[-2,0,3,5,3\]

**Explanation:**

Initial state:
\[0,0,0,0,0\]

After applying operation \[1,3,2\]:
\[0,2,2,2,0\]

After applying operation \[2,4,3\]:
\[0,2,5,5,3\]

After applying operation \[0,2,-2\]:
\[-2,0,3,5,3\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> m;
        for(auto u : updates) {
            m[u[0]] += u[2];
            m[u[1] + 1] -= u[2];
        }
        vector<int> ans(length);
        int cnt = 0;
        for(auto it = m.begin(); it != m.end(); ++it) {
            cnt += it->second;
            if(cnt != 0) {
                auto nt = it;
                ++nt;
                if(nt != m.end()) 
                    for(int i = it->first; i < nt->first; ++i)
                        ans[i] += cnt;
            }
        }
        return ans;
    }
};
```
      