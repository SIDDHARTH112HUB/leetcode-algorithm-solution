[127.word-ladder](https://leetcode.com/problems/word-ladder/)  

Given two words (_beginWord_ and _endWord_), and a dictionary's word list, find the length of shortest transformation sequence from _beginWord_ to _endWord_, such that:

1.  Only one letter can be changed at a time.
2.  Each transformed word must exist in the word list.

**Note:**

*   Return 0 if there is no such transformation sequence.
*   All words have the same length.
*   All words contain only lowercase alphabetic characters.
*   You may assume no duplicates in the word list.
*   You may assume _beginWord_ and _endWord_ are non-empty and are not the same.

**Example 1:**

  
**Input:**  
beginWord = "hit",  
endWord = "cog",  
wordList = \["hot","dot","dog","lot","log","cog"\]  
  
**Output:** 5  
  
**Explanation:** As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",  
return its length 5.  

**Example 2:**

  
**Input:**  
beginWord = "hit"  
endWord = "cog"  
wordList = \["hot","dot","dog","lot","log"\]  
  
**Output:** 0  
  
**Explanation:** The endWord "cog" is not in wordList, therefore no possible transformation.  



**Solution:**  

```cpp
class Solution {
public:
    
    int diff_count( string &a, string &b){
        int cnt = 0;
        for( int i = 0; i<a.size(); i++){
            if( a[i] != b[i])
                cnt++;
        }
        return cnt;
    }
    int ladderLength(string start, string end, vector<string>& bank) {
        if( bank.size() == 0 ) return -1;
        bank.push_back(start);
        int n = bank.size();
        vector<vector<int> > dist(n, vector<int>(n, 0));

        for( int i = 0; i < bank.size(); i++){
            for( int j = i+1; j<bank.size(); j++){
                dist[i][j] = diff_count(bank[i], bank[j]);
            }
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push( n - 1);
        int ans = 1;
        while( q.size() ){
            int len = q.size();
            ++ans;
            for( int i = 0; i<len; i++){
                int t = q.front();q.pop();
                visited.insert(t);
                for( int j = 0; j<n; j++ ){
                    if( ( dist[j][t] != 1 && dist[t][j]!=1 )  || visited.count(j) != 0 ) continue;
                    if( bank[j] == end ) return ans;
                    q.push(j);
                }
            }
        }
        return 0;
        
    }
};
```
      