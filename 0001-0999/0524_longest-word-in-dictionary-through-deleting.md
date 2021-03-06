[524.longest-word-in-dictionary-through-deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)  

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

**Example 1:**  

  
**Input:**
  
s = "abpcplea", d = \["ale","apple","monkey","plea"\]
  

  
**Output:** 
  
"apple"
  

**Example 2:**  

  
**Input:**
  
s = "abpcplea", d = \["a","b","c"\]
  

  
**Output:** 
  
"a"
  

**Note:**  

1.  All the strings in the input will only contain lower-case letters.
2.  The size of the dictionary won't exceed 1,000.
3.  The length of all the strings in the input won't exceed 1,000.  



**Solution:**  

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans= "";
        for( auto &str:d){
            if( str.size() > s.size() )
                continue;
            
            int i = 0, j=0;
            while( i<s.size() && j<str.size()){
                if( s[i] == str[j])
                    j++;
                i++;
            }
            if( j == str.size() ){
                if( ans == "")
                    ans = str;
                else{
                    if( ans.size() <= str.size() ){
                        if( ans.size() == str.size() )
                            ans = min(ans, str);
                        else
                            ans = str;
                    }
                }
            }
        }
        return ans;
    }
};
```
      