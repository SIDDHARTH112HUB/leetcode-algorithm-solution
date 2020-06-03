//Link: https://leetcode.com/problems/longest-string-chain/ 
class Solution {
public:
    int longestStrChain(vector<string>& _words) {
        unordered_set<string> words(_words.begin(), _words.end());
        vector<unordered_map<string, int> > m(16);
        for(auto &s : words){
            m[s.size() - 1][s] = 1;
        }
        int ans = 1;
        for(int i = 1; i < 16; ++i) {
            for(auto &it : m[i]){
                auto &str = it.first;
                auto &cnt = it.second;
                for(int j = 0; j < str.size(); ++j){
                    string ns = str.substr(0, j) + str.substr(j+1);
                    if(words.count(ns)){
                        cnt = max(cnt, m[i-1][ns]+1);
                        ans = max(ans, cnt);
                    }
                }
            }
        }
        return ans;
    }
};