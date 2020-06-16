[784.letter-case-permutation](https://leetcode.com/problems/letter-case-permutation/)  

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

  
**Examples:**
  
**Input:** S = "a1b2"
  
**Output:** \["a1b2", "a1B2", "A1b2", "A1B2"\]
  

  
**Input:** S = "3z4"
  
**Output:** \["3z4", "3Z4"\]
  

  
**Input:** S = "12345"
  
**Output:** \["12345"\]
  

**Note:**

*   `S` will be a string with length between `1` and `12`.
*   `S` will consist only of letters or digits.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int size = S.length();
        vector<string> ans;
        
        for( int i = 0; i<size; i++ ){
            if( S[i] < 'A')
                continue;
            if( ans.size() == 0 )
                ans.push_back(S);
            int ans_size = ans.size();
            for( int j = 0; j<ans_size; j++){
                auto s = ans[j];
                if( s[i] > 'Z')
                    s[i] -= ('a'-'A');
                else
                    s[i] += ('a'-'A');
                ans.push_back(s);
            }
        }
        if( ans.size() == 0)
            ans.push_back(S);
        return ans;
    }
};
```
      