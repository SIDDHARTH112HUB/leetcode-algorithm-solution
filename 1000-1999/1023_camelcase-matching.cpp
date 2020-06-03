//Link: https://leetcode.com/problems/camelcase-matching/ 
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto &q : queries) {
            int i = 0, j = 0;
            bool res = true;
            while(i < q.size()) {
                if( j>= pattern.size()) {
                    if(q[i] <= 'Z') {
                        break;
                    }
                    ++i;
                    continue;
                }
                if(q[i] == pattern[j]) {
                    ++i; ++j;
                }else {
                    if(q[i] >= 'a'){
                        ++i;
                    }else{
                        break;
                    }
                }
                
            }
            ans.push_back(i == q.size() && j == pattern.size());
        }
        return ans;
    }
};