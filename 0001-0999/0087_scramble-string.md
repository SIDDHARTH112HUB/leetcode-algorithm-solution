[87.scramble-string](https://leetcode.com/problems/scramble-string/)  

Given a string _s1_, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of _s1_ = `"great"`:

  
    great
  
   /    \\
  
  gr    eat
  
 / \\    /  \\
  
g   r  e   at
  
           / \\
  
          a   t
  

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node `"gr"` and swap its two children, it produces a scrambled string `"rgeat"`.

  
    rgeat
  
   /    \\
  
  rg    eat
  
 / \\    /  \\
  
r   g  e   at
  
           / \\
  
          a   t
  

We say that `"rgeat"` is a scrambled string of `"great"`.

Similarly, if we continue to swap the children of nodes `"eat"` and `"at"`, it produces a scrambled string `"rgtae"`.

  
    rgtae
  
   /    \\
  
  rg    tae
  
 / \\    /  \\
  
r   g  ta  e
  
       / \\
  
      t   a
  

We say that `"rgtae"` is a scrambled string of `"great"`.

Given two strings _s1_ and _s2_ of the same length, determine if _s2_ is a scrambled string of _s1_.

**Example 1:**

  
**Input:** s1 = "great", s2 = "rgeat"
  
**Output:** true
  

**Example 2:**

  
**Input:** s1 = "abcde", s2 = "caebd"
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if( s1 == s2 )
            return true;
        int h[26]= {0};
        for( char c :s1){
            ++h[c-'a'];
        }
        for( char c :s2){
            --h[c-'a'];
        }
        for( int i = 0; i<26; i++){
            if( h[i] != 0 ) 
                return false;
        }
        int len = s1.size();
        for( int i = 1; i < s1.size(); i++ ){
            if( isScramble(s1.substr(0, i), s2.substr(0, i) ) && 
               isScramble(s1.substr(i), s2.substr(i)) )
                return true;
            if( isScramble(s1.substr(0, i), s2.substr(len-i) ) && 
               isScramble(s1.substr(i), s2.substr(0, len-i)) )
                return true;
            
        }
        return false;
    }
};
```
      