//Link: https://leetcode.com/problems/prefix-and-suffix-search/ 
struct Trie{
    Trie *nodes[26];
    int weight;
    Trie(){
        weight = -1;
        memset(nodes, 0, sizeof(nodes));
    }
    void insert(string &s, int weight){
        auto node = this;
        for( int i = 0; i<s.size(); i++){
            int c = s[i]-'a';
            if( node->nodes[c] == NULL ){
                node->nodes[c] = new Trie();
            }
            node = node->nodes[c];
        }
        node->weight = weight;
    }
    
    Trie* getTrie(string &s){
        Trie *preT = this;
        for( int i = 0; i<s.size(); i++){
            char c = s[i]-'a';
            preT = preT->nodes[c];
            if( preT == NULL )
                return NULL;
        }
        return preT;
    }
    int get_weight(string &pre, set<int> &s){
        auto preT = this->getTrie(pre);
        if( preT == NULL )
            return -1;
        int ans = 0;
        helper(preT, s);
        return ans;
    }
    
    void helper(Trie *t, set<int> &s){
        if( t->weight >= 0 ){
            s.insert(t->weight);
        }
        for( int i = 0; i<26; i++){
            if( t->nodes[i] ){
                helper(t->nodes[i], s);
            }
        }
    }
};

class WordFilter {
public:
    Trie *preT;
    Trie *sufT;
    WordFilter(vector<string> words) {
        preT = new Trie();
        sufT = new Trie();
        for( int i = 0; i<words.size(); i++ ){
            auto &s = words[i];
            preT->insert(s, i);
            reverse(s.begin(), s.end());
            //cout<<s<<endl;
            sufT->insert(s, i);
        }
    }
    
    int f(string prefix, string suffix) {
        set<int> s1,s2;
        reverse(suffix.begin(), suffix.end());
        preT->get_weight(prefix, s1);
        sufT->get_weight(suffix, s2);
        if( s1.size() == 0 || s2.size() == 0 )
            return -1;
        int ans = 0;
        for( auto n:s1){
            if( s2.count(n) )
                ans = max(n,ans);
        }
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */