[686.repeated-string-match](https://leetcode.com/problems/repeated-string-match/)  

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

**Note:**  
The length of `A` and `B` will be between 1 and 10000.  



**Solution:**  

```cpp
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        int cnt = 1;
        while( t.size() < B.size()){
            t+=A;
            cnt++;
        }
        int i = t.find(B);
        if( i != string::npos ) return cnt;
        t+=A;
        i = t.find(B);
        cnt++;
        if( i != string::npos ) return cnt;
        return -1;
    }
};
```
      