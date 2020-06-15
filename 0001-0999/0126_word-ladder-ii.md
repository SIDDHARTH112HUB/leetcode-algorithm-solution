[126.word-ladder-ii](https://leetcode.com/problems/word-ladder-ii/)  

Given two words (_beginWord_ and _endWord_), and a dictionary's word list, find all shortest transformation sequence(s) from _beginWord_ to _endWord_, such that:

1.  Only one letter can be changed at a time
2.  Each transformed word must exist in the word list. Note that _beginWord_ is _not_ a transformed word.

**Note:**

*   Return an empty list if there is no such transformation sequence.
*   All words have the same length.
*   All words contain only lowercase alphabetic characters.
*   You may assume no duplicates in the word list.
*   You may assume _beginWord_ and _endWord_ are non-empty and are not the same.

**Example 1:**

**Input:**
beginWord = "hit",
endWord = "cog",
wordList = \["hot","dot","dog","lot","log","cog"\]

**Output:**
\[
  \["hit","hot","dot","dog","cog"\],
  \["hit","hot","lot","log","cog"\]
\]

**Example 2:**

**Input:**
beginWord = "hit"
endWord = "cog"
wordList = \["hot","dot","dog","lot","log"\]

**Output:** \[\]

**Explanation:** The endWord "cog" is not in wordList, therefore no possible transformation.  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(), wordList.end());
        if( m.count(endWord) == 0 ) return {};
        queue<vector< string> > q;
        q.push({beginWord});
        vector<vector<string > > ans;
        unordered_set<string> words;
        int minLevel = INT_MAX;
        int level = 1;
        while( q.size() ){
            //int size = q.size();
            //while( size-- > 0 ){
            auto path = q.front();
            if( path.size() > level){
                for( auto &w:words) m.erase(w);
                words.clear();
                level = path.size();
                if( level > minLevel ) break;
            }
            q.pop();
            string word = path.back();
            for(auto &c : word){
                int src = c;
                for( char i = 'a'; i<='z'; i++){
                    c = i;
                    if( m.count(word) == 0 ) {
                        c = src;
                        continue;
                    }
                    auto nextPath = path;
                    nextPath.push_back(word);
                    words.insert(word);
                    if( word == endWord ){
                        minLevel = nextPath.size();
                        ans.push_back(nextPath);
                    }
                    else
                        q.push(nextPath);
                    c = src;
                }
            }
           // }
        }
        return ans;
    }
};
```
      