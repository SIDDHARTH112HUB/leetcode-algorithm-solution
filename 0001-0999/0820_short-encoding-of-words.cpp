//Link: https://leetcode.com/problems/short-encoding-of-words/ 
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for( auto &w:words){
            for( int i = 1; i < w.length(); i++ ){
                s.erase(w.substr(i));
            }
        }
        int ans = 0;
        for(auto &str:s){
            ans += str.length()+1;
        }
        return ans;
    }
};