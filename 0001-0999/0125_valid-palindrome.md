[125.valid-palindrome](https://leetcode.com/problems/valid-palindrome/)  

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

**Note:** For the purpose of this problem, we define empty string as valid palindrome.

**Example 1:**

**Input:** "A man, a plan, a canal: Panama"
**Output:** true

**Example 2:**

**Input:** "race a car"
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool isAlphanumeric(char &c)
    {
        if( c<'0' || (c>'9' && c<'A') || (c>'Z' && c<'a') || c>'z')
            return false;
        if ( c>='a') c -=('a' - 'A');
        return true;
    }
    bool isPalindrome(string s) {
        int right_idx = s.length()-1;
        for(int i=0;i<s.length();i++)
        {
            char c = s.at(i);
            if( isAlphanumeric(c) == false ) continue;
            
            char rc;
            do
            {
                rc = s.at(right_idx--);
            }while( isAlphanumeric(rc) == false );
            
            if( c != rc ) return false;
        }
        return true;
    }
};
```
      