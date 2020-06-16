[22.generate-parentheses](https://leetcode.com/problems/generate-parentheses/)  

Given _n_ pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given _n_ = 3, a solution set is:

  
\[
  
  "((()))",
  
  "(()())",
  
  "(())()",
  
  "()(())",
  
  "()()()"
  
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, n, n);
        return ans;
    }
    void dfs(string s, int l, int r){
        if( l == 0 && r==0){
            ans.push_back(s);
            return;
        }
        if(l < 0 || r < 0) return;
        
        if( l <= r ){
            dfs(s + "(", l - 1, r);
            dfs(s + ")", l, r - 1);
        }
    }
};
```
      