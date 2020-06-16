[3.longest-substring-without-repeating-characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  

Given a string, find the length of the **longest substring** without repeating characters.

**Example 1:**

  
**Input:** "abcabcbb"
  
**Output:** 3 
  
**Explanation:** The answer is `"abc"`, with the length of 3. 
  

**Example 2:**

  
**Input:** "bbbbb"
  
**Output:** 1 **Explanation:** The answer is `"b"`, with the length of 1.
  

**Example 3:**

  
**Input:** "pwwkew"
  
**Output:** 3 **Explanation:** The answer is `"wke"`, with the length of 3. 
  
             Note that the answer must be a **substring**, `"pwke"` is a _subsequence_ and not a substring.  



**Solution:**  

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);
        
        int begin =0, end=0, d=0, counter=0,ans=0, head=0;
        while( end<s.size()){
            if(hash[s[end++]]++ > 0 ) counter++;
            
            while( counter>0){
                ans = max(ans, end-begin-1);
                if( hash[s[begin++]]-->1) counter--;
            }
            
            
        }
        ans = max(ans, end-begin);
        return ans;
    }
};
```
      