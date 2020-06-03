//Link: https://leetcode.com/problems/longest-word-in-dictionary/ 
struct Trie{
    map<char, Trie*> node;
    bool flag;
    Trie(){
        flag = false;
    }
    void build(vector<string> &words){
        
        for( string &str:words){
            auto cur = this;
            //cout<<str<<endl;
            for( char c:str){
                if( !cur->node[c] ){
                    auto n = new Trie();
                    cur->node[c] = n;
                }
                cur  = cur->node[c];
            }
            cur->flag = true;
        }
    }
    void find(Trie* trie,string &ans, string &res){
        if( !trie ) return;
        for( auto it:trie->node){
            if( it.second->flag == true ){
                res += it.first;
                find(it.second, ans, res);
                if( res.size() > ans.size() ) 
                    ans = res;
                res.pop_back();
            }
        }
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        trie.build(words);
        string res, ans;
        trie.find(&trie,ans, res);
        return ans;
    }
    /*
        sort(words.begin(), words.end());
        set<string> dict(words.begin(), words.end());
        string res = "";
        string ans = "";
        queue<string> q;
        q.push("");
        while(q.size() ){
            string &str = q.front();
            for( char i='a'; i<='z'; i++){
                string s1 = str+i;
                if( dict.find(s1) != dict.end() ){
                    q.push(s1);
                    if( s1.size()> ans.size())
                        ans = s1;
                }
            }
            q.pop();
        }
        return ans;
    }*/
};