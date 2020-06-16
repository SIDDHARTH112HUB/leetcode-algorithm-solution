[387.first-unique-character-in-a-string](https://leetcode.com/problems/first-unique-character-in-a-string/)  

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

**Examples:**

  
s = "leetcode"  
return 0.  
  
s = "loveleetcode",  
return 2.  

**Note:** You may assume the string contain only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int idx = 1;
        for( char c:s){
            ++arr[c-'a'];
        }
        for(int i = 0; i < s.size(); ++i)
            if(arr[s[i]-'a'] == 1) return i;
        return -1;
    }
};
```
      