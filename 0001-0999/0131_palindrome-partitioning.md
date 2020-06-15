[131.palindrome-partitioning](https://leetcode.com/problems/palindrome-partitioning/)  

Given a string _s_, partition _s_ such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of _s_.

**Example:**

**Input:** "aab"
**Output:**
\[
  \["aa","b"\],
  \["a","a","b"\]
\]  



**Solution:**  

```cpp
class Solution {
public:
    bool isPalindrome( string &s, int l, int r){
        while(l<r){
            if( s[l++] != s[r--])
                return false;
        }
        
        return true;
    }
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> item;
        dfs(s, 0, item);
        return ans;
    }
    
    void dfs(string &s, int idx, vector<string> &item){
        if( idx >= s.size()){
            ans.push_back(item);
            return;
        }
        for( int i =idx; i<s.size(); i++){
            if( isPalindrome(s, idx, i) ){
                item.push_back(s.substr(idx,i-idx+1));
                dfs(s, i+1, item);
                item.pop_back();
            }
        }
    }
};
```
      