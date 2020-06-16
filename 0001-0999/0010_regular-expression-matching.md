[10.regular-expression-matching](https://leetcode.com/problems/regular-expression-matching/)  

Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.

  
'.' Matches any single character.  
'\*' Matches zero or more of the preceding element.  

The matching should cover the **entire** input string (not partial).

**Note:**

*   `s` could be empty and contains only lowercase letters `a-z`.
*   `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.

**Example 1:**

  
**Input:**  
s = "aa"  
p = "a"  
**Output:** false  
**Explanation:** "a" does not match the entire string "aa".  

**Example 2:**

  
**Input:**  
s = "aa"  
p = "a\*"  
**Output:** true  
**Explanation:** '\*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".  

**Example 3:**

  
**Input:**  
s = "ab"  
p = ".\*"  
**Output:** true  
**Explanation:** ".\*" means "zero or more (\*) of any character (.)".  

**Example 4:**

  
**Input:**  
s = "aab"  
p = "c\*a\*b"  
**Output:** true  
**Explanation:** c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".  

**Example 5:**

  
**Input:**  
s = "mississippi"  
p = "mis\*is\*p\*."  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool match( char* s, char*  p){
        //if( *s=='\0' ) return *p!='.';
        if(*p =='\0') return *s=='\0';
        //printf("%s %s \n", s,p);
        if( p[1] == '*' )
            return match_star(p[0], p+2, s );
        if( *s !=  '\0' && ( *s == *p || *p=='.' )){
            return match(++s, ++p);
        }
        return 0;
    }
    bool match_star(char c, char* p, char* s){
        do{
            if( match(s, p) )
                return 1;
        }while( *s != '\0' && (*s++ == c || c == '.'));
        return 0;
    }
    bool isMatch(string s, string p) {
        
        //if( s.length() == 0 ) return 0;
        //if( p.length() == 0 ) return 0;
        char* cs = (char*)s.c_str();
        char* cp = (char*)p.c_str();
        do{
            if( this->match( cs, cp ) )
                return 1;
            //cs++;
        }while(false);
        return 0;
    }
};
```
      