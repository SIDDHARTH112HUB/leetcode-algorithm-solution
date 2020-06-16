[336.palindrome-pairs](https://leetcode.com/problems/palindrome-pairs/)  

Given a list of **unique** words, find all pairs of **_distinct_** indices `(i, j)` in the given list, so that the concatenation of the two words, i.e. `words[i] + words[j]` is a palindrome.

**Example 1:**

  
**Input:** \["abcd","dcba","lls","s","sssll"\]
  
**Output:** \[\[0,1\],\[1,0\],\[3,2\],\[2,4\]\] 
  
**E****xplanation:** The palindromes are `["dcbaabcd","abcddcba","slls","llssssll"]`
  

**Example 2:**

  
**Input:** \["bat","tab","cat"\]
  
**Output:** \[\[0,1\],\[1,0\]\] **E****xplanation:** The palindromes are `["battab","tabbat"]`  



**Solution:**  

```cpp
class Solution {
public:
    bool isPalindrome(string &word){
        int l = 0, r = word.size()-1;
        while(l < r){
            if( word[l] != word[r])return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<char, map<string, int> > dict;
        unordered_set<int> parlindrome;
        for( int i = 0; i<words.size(); i++){
            string &str = words[i];
            if( str.size() > 0 )
                dict[str.back()][str] = i;
            else{
                for( char a = 'a'; a<='z'; a++){
                    dict[a][str] = i;
                }
            }
            if( isPalindrome(str) ){
                parlindrome.insert(i);
            }
        }
        for( int i = 0; i<words.size(); i++){
            string word = words[i];
            if( word.size() == 0 ){
                for( auto num: parlindrome){
                    if( num == i || ( i> num && words[num] == words[i]))
                        continue;
                    ans.push_back({i, num});
                }
                continue;
            }
            for(auto &it: dict[word[0]]){
                if( it.second == i )continue;
                string str = word + it.first;
                if( isPalindrome(str)){
                    ans.push_back({i, it.second});
                }
            }
        }
        return ans;
    }
};
```
      