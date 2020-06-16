[186.reverse-words-in-a-string-ii](https://leetcode.com/problems/reverse-words-in-a-string-ii/)  

Given an input string , reverse the string word by word. 

**Example:**

  
**Input:** \["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"\]
  
**Output:** \["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"\]

**Note:** 

*   A word is defined as a sequence of non-space characters.
*   The input string does not contain leading or trailing spaces.
*   The words are always separated by a single space.

**Follow up:** Could you do it _in-place_ without allocating extra space?  



**Solution:**  

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int j = 0;
        s.push_back(' ');
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        s.pop_back();
    }
};
```
      