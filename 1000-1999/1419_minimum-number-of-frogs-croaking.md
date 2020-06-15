[1419.minimum-number-of-frogs-croaking](https://leetcode.com/problems/minimum-number-of-frogs-croaking/)  

Given the string `croakOfFrogs`, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. _Return the minimum number of_ different _frogs to finish all the croak in the given string._

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ **sequentially**. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

**Example 1:**

**Input:** croakOfFrogs = "croakcroak"
**Output:** 1 
**Explanation:** One frog yelling "croak**"** twice.

**Example 2:**

**Input:** croakOfFrogs = "crcoakroak"
**Output:** 2 
**Explanation:** The minimum number of frogs is two. 
The first frog could yell "**cr**c**oak**roak".
The second frog could yell later "cr**c**oak**roak**".

**Example 3:**

**Input:** croakOfFrogs = "croakcrook"
**Output:** -1
**Explanation:** The given string is an invalid combination of "croak**"** from different frogs.

**Example 4:**

**Input:** croakOfFrogs = "croakcroa"
**Output:** -1

**Constraints:**

*   `1 <= croakOfFrogs.length <= 10^5`
*   All characters in the string are: `'c'`, `'r'`, `'o'`, `'a'` or `'k'`.  



**Solution:**  

```cpp
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int ans = 0;
        for(auto ch : croakOfFrogs) {
            if(ch == 'c'){
                ++c;
            }else if( ch == 'r') {
                if(c <= 0)
                    return -1;
                --c;
                ++r;
            }else if(ch == 'o') {
                if(r <= 0)
                    return -1;
                --r;
                ++o;
            }else if(ch == 'a') {
                if(o <=0) return -1;
                --o;
                ++a;
            }else if(ch == 'k') {
                if(a <= 0) return -1;
                --a;
            }
            ans = max(ans, c + r + o + a);
        }
        if(c > 0 || r > 0 || o > 0 || a > 0) return -1;
        return ans;
    }
};
```
      