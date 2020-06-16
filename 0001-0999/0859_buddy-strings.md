[859.buddy-strings](https://leetcode.com/problems/buddy-strings/)  

Given two strings `A` and `B` of lowercase letters, return `true` if and only if we can swap two letters in `A` so that the result equals `B`.

**Example 1:**

  
**Input:** A = "ab", B = "ba"
  
**Output:** true
  

**Example 2:**

  
**Input:** A = "ab", B = "ab"
  
**Output:** false
  

**Example 3:**

  
**Input:** A = "aa", B = "aa"
  
**Output:** true
  

**Example 4:**

  
**Input:** A = "aaaaaaabc", B = "aaaaaaacb"
  
**Output:** true
  

**Example 5:**

  
**Input:** A = "", B = "aa"
  
**Output:** false
  

**Note:**

1.  `0 <= A.length <= 20000`
2.  `0 <= B.length <= 20000`
3.  `A` and `B` consist only of lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if( A.size() != B.size() ) return false;
        if( A == B ){
            int hash[128] = {0};
            for( char c : A){
                hash[c]++;
            }
            for(int i = 0; i<128; i++){
                if( hash[i] %2 == 0 && hash[i]>0 )
                    return true;
            }
            return false;
        }
        int cnt=0;
        int i1 = -1, i2 =-1;
        for( int i = 0; i<A.size(); i++ ){
            if( A[i] != B[i]){
                cnt++;
                if(cnt>2)
                    return false;
                if(i1==-1){
                    i1 = i;
                }else{
                    i2 = i;
                    if( A[i1] != B[i] || B[i1] != A[i] )
                        return false;
                }
            }
        }
        if( i1 != -1 && i2 == -1 )
            return false;
        return cnt == 2;
    }
};
```
      