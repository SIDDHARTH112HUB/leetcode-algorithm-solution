//Link: https://leetcode.com/problems/brace-expansion-ii/ 
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int idx = 0;
        unordered_set<string> ans;
        helper(expression, idx, ans);
        auto res = vector<string>(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        return res;
    }
    void crossjoin(unordered_set<string> &v1, unordered_set<string> &v2) {
        if(v1.size() == 0){
            v1 = v2;
            return;
        }
        if(v2.size() == 0)return;
        auto src = v1;
        v1.clear();
        for(auto &s1:src) {
            for(auto &s2: v2){
                v1.insert(s1 + s2);
            }
        }
    }
    void combine(unordered_set<string> &v1, unordered_set<string> &v2) {
        for(auto &s : v2)
            v1.insert(s);
    }
    unordered_set<string> helper(string &e, int &idx, unordered_set<string> &ans) {
        while(idx < e.size()) {
            char c = e[idx];
            if(c == ',') {
                unordered_set<string> res;
                helper(e, ++idx, res);
                combine(ans, res);
            }else if(c == '{'){
                unordered_set<string> res;
                helper(e, ++idx, res);
                ++idx; //skip "}"
                crossjoin(ans, res);
            }else if(c == '}'){
                return ans;
            }else{
                string s;
                while(idx < e.size() && e[idx] >='a' && e[idx] <='z' )
                    s += e[idx++];
                unordered_set<string> v = {s};
                crossjoin(ans, v);
            }
        }
        return ans;
    }
};