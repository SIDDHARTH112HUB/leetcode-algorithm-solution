[58.length-of-last-word](https://leetcode.com/problems/length-of-last-word/)  

Given a string _s_ consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

**Note:** A word is defined as a **maximal substring** consisting of non-space characters only.

**Example:**

  
**Input:** "Hello World"  
**Output:** 5  



**Solution:**  

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size()-1;
        int ans = 0;
        while(end>=0 && s[end]==' ')
            end--;
        
        while( end >= 0 && s[end--] != ' ' )
            ans++;
        return ans;
    }
};
```
      