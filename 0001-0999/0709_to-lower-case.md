[709.to-lower-case](https://leetcode.com/problems/to-lower-case/)  

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

**Example 1:**

**Input:** "Hello"
**Output:** "hello"

**Example 2:**

**Input:** "here"
**Output:** "here"

**Example 3:**

**Input:** "LOVELY"
**Output:** "lovely"  



**Solution:**  

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        int diff = 'a'-'A';
        for( char &c : str){
            if( c<='Z' && c>='A'){
                c+=diff;
            }
        }
        return str;
    }
};
```
      