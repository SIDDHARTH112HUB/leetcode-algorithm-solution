[763.partition-labels](https://leetcode.com/problems/partition-labels/)  

A string `S` of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

**Example 1:**

  
**Input:** S = "ababcbacadefegdehijhklij"  
**Output:** \[9,7,8\]  
**Explanation:**  
The partition is "ababcbaca", "defegde", "hijhklij".  
This is a partition so that each letter appears in at most one part.  
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.  

**Note:**

*   `S` will have length in range `[1, 500]`.
*   `S` will consist of lowercase English letters (`'a'` to `'z'`) only.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int right[128] = {0};
        for(int i = S.size() - 1; i >= 0; --i) {
            if(right[S[i]] == 0)
                right[S[i]] = i;
        }
        vector<int> ans;
        int mxRight = 0, prev = -1;
        for(int i = 0; i < S.size(); ++i) {
            mxRight = max(mxRight, right[S[i]]);
            if(mxRight == i) {
                ans.push_back(i - prev);
                prev = i;
                mxRight = 0;
            }
        }
        return ans;
    }
};
```
      