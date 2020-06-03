//Link: https://leetcode.com/problems/smallest-sufficient-team/ 
class Solution {
public:
    map<string, vector<int> > skill;
    vector<int> ans;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for(int i = 0; i < people.size(); ++i) {
            auto &p = people[i];
            for(auto &s : p){
                skill[s].push_back(i);
            }
        }
        unordered_map<string, int> s;
        vector<int> item;
        dfs(req_skills, people, s, item);
        return ans;
    }
    
    void dfs(vector<string>& req_skills, vector<vector<string>>& people, unordered_map<string, int> &s, vector<int> &item) {
        if(s.size() == req_skills.size()){
            if(ans.size() == 0 || ans.size() > item.size())
                ans = item;
            return;
        }
        if(ans.size() > 0 && ans.size() <= item.size())
            return;
        for(auto &sk : req_skills) {
            if(s.find(sk) == s.end() ){
                for(auto p : skill[sk]){
                    for(auto &psk : people[p]){
                        ++s[psk];
                    }
                    item.push_back(p);
                    dfs(req_skills, people, s, item);
                    item.pop_back();
                    for(auto &psk : people[p]){
                        --s[psk];
                        if(s[psk] == 0)
                            s.erase(psk);
                    }
                }
                break;
            }
            
        }
    }
};