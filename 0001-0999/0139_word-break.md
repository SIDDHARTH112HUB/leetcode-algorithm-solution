[139.word-break](https://leetcode.com/problems/word-break/)  

Given a **non-empty** string _s_ and a dictionary _wordDict_ containing a list of **non-empty** words, determine if _s_ can be segmented into a space-separated sequence of one or more dictionary words.

**Note:**

*   The same word in the dictionary may be reused multiple times in the segmentation.
*   You may assume the dictionary does not contain duplicate words.

**Example 1:**

  
**Input:** s = "leetcode", wordDict = \["leet", "code"\]
  
**Output:** true
  
**Explanation:** Return true because `"leetcode"` can be segmented as `"leet code"`.
  

**Example 2:**

  
**Input:** s = "applepenapple", wordDict = \["apple", "pen"\]
  
**Output:** true
  
**Explanation:** Return true because `"`applepenapple`"` can be segmented as `"`apple pen apple`"`.
  
             Note that you are allowed to reuse a dictionary word.
  

**Example 3:**

  
**Input:** s = "catsandog", wordDict = \["cats", "dog", "sand", "and", "cat"\]
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int dp[s.size()+1] = {0};
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            if( dict.count(s.substr(0, i) ) ){
                dp[i] = true;
                continue;
            }
            for( int j = 0; j<i; j++){
                if( dp[j] && dict.count( s.substr( j, i-j ) ) ){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```
      