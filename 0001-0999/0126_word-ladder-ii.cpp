//Link: https://leetcode.com/problems/word-ladder-ii/ 
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