//Link: https://leetcode.com/problems/accounts-merge/ 


class Solution {
public:
    map<string, string> m;
    map<string, string> owner;
    map<string, vector<string> > group;
    string find(const string &a) {
        if(m.count(a))
            return a == m[a] ? a : (m[a] = find(m[a]));
        return m[a] = a;
    }
    
    void un(string &a, string &b) {
        m[find(b)] = find(a);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &l : accounts) {
            for(int i = 1; i < l.size(); ++i) {
                owner[l[i]] = l[0];
                un(l[i], l[i+1 >= l.size() ? i : (i + 1 )]);
            }
        }
        for(auto it : m) {
            group[find(it.first)].push_back(it.first);
        }
        vector<vector<string> > ans;
        for(auto it : group) {
            sort(it.second.begin(), it.second.end());
            ans.push_back({owner[it.first]});
            for(auto &a : it.second) {
                ans.back().push_back(a);
            }
        }
        return ans;
    }
};