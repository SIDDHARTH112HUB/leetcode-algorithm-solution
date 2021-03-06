[467.unique-substrings-in-wraparound-string](https://leetcode.com/problems/unique-substrings-in-wraparound-string/)  

Consider the string `s` to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so `s` will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string `p`. Your job is to find out how many unique non-empty substrings of `p` are present in `s`. In particular, your input is the string `p` and you need to output the number of different non-empty substrings of `p` in the string `s`.

**Note:** `p` consists of only lowercase English letters and the size of p might be over 10000.

**Example 1:**  

  
**Input:** "a"
  
**Output:** 1
  

  
**Explanation:** Only the substring "a" of string "a" is in the string s.
  

**Example 2:**  

  
**Input:** "cac"
  
**Output:** 2
  
**Explanation:** There are two substrings "a", "c" of string "cac" in the string s.
  

**Example 3:**  

  
**Input:** "zab"
  
**Output:** 6
  
**Explanation:** There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.  



**Solution:**  

```cpp
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> vec(26);
        int len = 1;
        for( int i = p.size()-1; i>=0; i--){
            
            if( i <p.size()-1 && (( p[i+1] - 1 == p[i]) || ( p[i+1] == 'a' && p[i] == 'z' ) ) ){
                len += 1;
            }else{
                len = 1;
            }
            vec[p[i]-'a'] = max(vec[p[i]-'a'], len);
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};
```
      