[214.shortest-palindrome](https://leetcode.com/problems/shortest-palindrome/)  

Given a string _**s**_, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

**Example 1:**

  
**Input:** `"aacecaaa"`
  
**Output:** `"aaacecaaa"`
  

**Example 2:**

  
**Input:** `"abcd"`
  
**Output:** `"dcbabcd"`  



**Solution:**  

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = 1;
        for( int i = s.size()-1; i>0; i--){
            int l = 0, r = i;
            while(l<r){
                if( s[l] != s[r] ) break;
                l++;
                r--;
            }
            if( l >= r){
                len = i+1;
                break;
            }
        }
        if( len >=  s.size() )
            return s;
        string prefix = s.substr(len);
        reverse(prefix.begin(), prefix.end() );
        return prefix + s;
    }
};
```
      