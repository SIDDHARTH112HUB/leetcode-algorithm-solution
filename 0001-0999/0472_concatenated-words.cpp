//Link: https://leetcode.com/problems/concatenated-words/ 


int cmp(string& a, string& b){
    return a.size() < b.size();
}

class Solution {
public:
    unordered_map<string, int> appear;
    vector<string> ans;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        //set<string> word_set(words.begin(), words.end());
        //for( int i = 0; i<words.length(); i++ ){
        for( string& word:words){
            if( word.length() == 0 )
                continue;
            if( solve(word, 0) )
                ans.push_back(word);
            appear[word] = 1;
            //cout<<word<<endl;
        }
        return ans;
    }
    
    int solve(string& word, int len){
        int size = word.size();
        if( len == size ) return 1;
        if( len > size ) return 0;
        
        for( int i = size - 1; i >= len; --i){
            if( appear[word.substr(len, i - len+1)] ){
                //cout<<"appear "<< word.substr(len, i - len+1)<<endl;
                if( solve( word, i+1 ) ){
                    return 1;
                }
            }
        }
        return 0;
    }
};