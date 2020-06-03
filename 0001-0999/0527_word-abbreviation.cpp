//Link: https://leetcode.com/problems/word-abbreviation/ 

class Solution {
public:
    vector<string> ans;
    map<string, vector<pair<string, int> > > m;
    string abbr(const string &s, int len) {
        if(s.size() <= 3) return s;
        auto str = s.substr(0, len) + to_string(s.size() - len - 1) + s.substr(s.size() - 1);
        if(str.size() == s.size()) return s;
        return str;
    }
    vector<string> wordsAbbreviation(vector<string>& d) {
        vector<string> ans(d.size());
        map<string, int> dict;
        for(int i = 0; i < d.size(); ++i) {
            dict[d[i]] = i;
        }
        
        int len = 1;
        
        while(dict.size()) {
            int idx = 0;
            for(const auto &it : dict) {
                auto &originString = it.first;
                auto index = it.second;
                auto ns = abbr(originString, len);
                m[ns].push_back({originString, index});
            }
            for(auto &it : m) {
                auto &arr = it.second;
                auto &originString = it.second[0].first;
                auto &shortString = it.first;
                int stringIdx = it.second[0].second;
                if(arr.size() == 1) {
                    ans[stringIdx] = shortString;
                    dict.erase(originString);
                }
            }
            m.clear();
            ++len;
        }
        
        return ans;
    }
};