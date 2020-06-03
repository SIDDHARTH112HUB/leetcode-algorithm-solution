//Link: https://leetcode.com/problems/word-subsets/ 
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<int, int> mb;
        for( auto &s:B){
            unordered_map<int, int> m;
            for( char c : s ){
                m[c]++;
            }
            for( auto it : m){
                char c = it.first;
                if( mb[c] < m[c] )
                    mb[c] = it.second;
            }
        }
        
        vector<string> ans;
        for( auto &s:A){
            unordered_map<int, int> m;
            for( char c : s ){
                m[c]++;
            }
            bool flag = true;
            for( auto &it: mb){
                char c = it.first;
                if( mb[c] > m[c]){
                    flag = false;
                    break;
                }
            }
            if( flag )
                ans.push_back(s);
        }
        return ans;
    }
};