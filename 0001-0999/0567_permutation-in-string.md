[567.permutation-in-string](https://leetcode.com/problems/permutation-in-string/)  

Given two strings **s1** and **s2**, write a function to return true if **s2** contains the permutation of **s1**. In other words, one of the first string's permutations is the **substring** of the second string.

**Example 1:**

  
**Input:** s1 = "ab" s2 = "eidbaooo"  
**Output:** True  
**Explanation:** s2 contains one permutation of s1 ("ba").  

**Example 2:**

  
**Input:**s1= "ab" s2 = "eidboaoo"  
**Output:** False  

**Constraints:**

*   The input strings only contain lower case letters.
*   The length of both given strings is in range \[1, 10,000\].  



**Solution:**  

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int begin = 0, end = 0,counter = 0;
        int hash[256] = {0};
        for( char c:s1)
            hash[c]++;
        while(end<s2.size()){
            if( hash[s2[end++]]-- == 0 ) counter++;
            while( counter > 0 ){
                if( hash[s2[begin++]]++ < 0 )counter--;
            }
            if( counter == 0 && end-begin >= s1.size() )
                return true;
        }
        return false;
    }
};
```
      