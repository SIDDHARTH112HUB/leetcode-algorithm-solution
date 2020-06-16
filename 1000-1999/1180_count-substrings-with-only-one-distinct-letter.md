[1180.count-substrings-with-only-one-distinct-letter](https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/)  

Given a string `S`, return the number of substrings that have only **one distinct** letter.

**Example 1:**

  
**Input:** S = "aaaba"  
**Output:** 8  
**Explanation:** The substrings with one distinct letter are "aaa", "aa", "a", "b".  
"aaa" occurs 1 time.  
"aa" occurs 2 times.  
"a" occurs 4 times.  
"b" occurs 1 time.  
So the answer is 1 + 2 + 4 + 1 = 8.  

**Example 2:**

  
**Input:** S = "aaaaaaaaaa"  
**Output:** 55  

**Constraints:**

*   `1 <= S.length <= 1000`
*   `S[i]` consists of only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int countLetters(string S) {
        int same = 1, ans = 0;
        S+= ' ';
        for(int i = 1; i < S.size(); ++i) {
            if(S[i-1] == S[i])
                ++same;
            else{
                ans += same * (same + 1) / 2;
                same = 1;
            }
        }
        return ans;
    }
};
```
      