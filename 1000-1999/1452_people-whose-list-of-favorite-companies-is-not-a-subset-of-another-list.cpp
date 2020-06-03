//Link: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/ 
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<unordered_set<string>> f;
        for(auto &fc : favoriteCompanies) {
            f.push_back({});
            for(auto &c : fc) {
                f.back().insert(c);
            }
        }
        vector<int> ans;
        for(int i = 0; i < f.size(); ++i) {
            bool flag = true;
            for(int j = 0; j < f.size(); ++j) {
                if(i == j) continue;
                bool flag2 = true;
                for(auto &name : f[i]) {
                    if(f[j].count(name) == 0) {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2 == true){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};