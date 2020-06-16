[1100.find-k-length-substrings-with-no-repeated-characters](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)  

Given a string `S`, return the number of substrings of length `K` with no repeated characters.

**Example 1:**

  
**Input:** S = "havefunonleetcode", K = 5
  
**Output:** 6
  
**Explanation:** 
  
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.
  

**Example 2:**

  
**Input:** S = "home", K = 5
  
**Output:** 0
  
**Explanation:** 
  
Notice K can be larger than the length of S. In this case is not possible to find any substring.
  

**Note:**

1.  `1 <= S.length <= 10^4`
2.  All characters of S are lowercase English letters.
3.  `1 <= K <= 10^4`  



**Solution:**  

```cpp
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(S.size() < K ) return 0;
        int prev = 0, cur = 0, ans = 0;
        map<int, int> m;
        for(int  i = 0; i < S.size(); ++i) {
            
            int c = S[i];
            if(i - prev > K-1){
                --m[S[prev]];
                ++prev;
            }
            ++m[c];
            while(m[c] > 1){
                --m[S[prev]];
                ++prev;
            }
            if(i - prev >= K-1){
                ++ans;
            }
        }
        return ans;
    }
};
```
      