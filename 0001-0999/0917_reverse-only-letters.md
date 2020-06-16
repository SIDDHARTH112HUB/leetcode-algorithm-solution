[917.reverse-only-letters](https://leetcode.com/problems/reverse-only-letters/)  

Given a string `S`, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

**Example 1:**

  
**Input:** "ab-cd"
  
**Output:** "dc-ba"
  

**Example 2:**

  
**Input:** "a-bC-dEf-ghIj"
  
**Output:** "j-Ih-gfE-dCba"
  

**Example 3:**

  
**Input:** "Test1ng-Leet=code-Q!"
  
**Output:** "Qedo1ct-eeLg=ntse-T!"
  

**Note:**

1.  `S.length <= 100`
2.  `33 <= S[i].ASCIIcode <= 122` 
3.  `S` doesn't contain `\` or `"`  



**Solution:**  

```cpp
class Solution {
public:
    bool isLetter(char c){
        return (c>='A' && c<='Z') || ( c>='a' && c<='z');
    }
    string reverseOnlyLetters(string S) {
        string ans = S;
        int j = S.size()-1;
        for( int i = 0; i<S.size(); i++ ){
            char c = S[i];
            if( isLetter(c) ){
                while( !isLetter(S[j])){
                   j--;
                }
                ans[i] = S[j];
                j--;
            }else{
                continue;
            }
        }
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      