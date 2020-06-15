[466.count-the-repetitions](https://leetcode.com/problems/count-the-repetitions/)  

Define `S = [s,n]` as the string S which consists of n connected strings s. For example, `["abc", 3]` ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where `S1=[s1,n1]` and `S2=[s2,n2]`. Find the maximum integer M such that `[S2,M]` can be obtained from `S1`.

**Example:**

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2  



**Solution:**  

```cpp
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();
        int cnt = 0, j = 0;
        vector<int> repeatCnt(n1 + 1);
        vector<int> next(n1 + 1);
        for(int k = 1; k <= n1; ++k) {
            for(int i = 0; i < l1; ++i){
                if(s1[i] == s2[j]){
                    ++j;
                }
                if(j == l2){
                    j = 0;
                    ++cnt;
                }
            }
            repeatCnt[k] = cnt;
            next[k] = j;
            for(int b = 0; b < k; ++b) {
                if(next[b] == j){
                    int interval = (k - b);
                    int repeat = (n1 - b) / interval;
                    int patternCnt = (repeatCnt[k] - repeatCnt[b]) * repeat;
                    int remainCnt = repeatCnt[b + (n1 - b) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return cnt / n2;
    }
};
```
      