//Link: https://leetcode.com/problems/find-and-replace-pattern/ 
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for( auto &word: words){
            unordered_map<int, int> m1,m2;
            bool flag = true;
            for( int i = 0; i<word.size(); i++){
                char wc = word[i], pc = pattern[i];
                if( m1[wc] == 0 && m2[pc] == 0 ){
                    m1[wc] = pc;
                    m2[pc] = wc;
                }else if( m1[wc] != pc || m2[pc] != wc){
                    flag = false;
                    break;
                }
            }
            if( flag )
                ans.push_back(word);
        }
        return ans;
    }
};