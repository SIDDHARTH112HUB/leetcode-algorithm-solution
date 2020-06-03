//Link: https://leetcode.com/problems/string-matching-in-an-array/ 
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        for(auto &w1 : words) {
            for(auto &w2 : words){
                if(w1 == w2) continue;
                if(w1.find(w2) != string::npos){
                    ans.insert(w2);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};