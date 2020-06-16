[345.reverse-vowels-of-a-string](https://leetcode.com/problems/reverse-vowels-of-a-string/)  

Write a function that takes a string as input and reverse only the vowels of a string.

**Example 1:**

  
**Input:** "hello"
  
**Output:** "holle"
  

**Example 2:**

  
**Input:** "leetcode"
  
**Output:** "leotcede"

**Note:**  
The vowels does not include the letter "y".  



**Solution:**  

```cpp
class Solution {
public:
    bool isv(char c) {
        return  c == 'a' || c=='e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c=='E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        if(s.size() == 0) return s;
        int i = 0, j = s.size()-1;
        while(i < j) {
            while(i < s.size() && !isv(s[i])) ++i;
            while(j >= 0 && !isv(s[j])) --j;
            if(i < s.size() && j >= 0 && i < j){
                swap(s[i], s[j]);
            }
            ++i, --j;
        }
        return s;
    }
};
```
      