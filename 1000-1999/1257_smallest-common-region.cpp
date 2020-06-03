//Link: https://leetcode.com/problems/smallest-common-region/ 
class Solution {
public:
    map<string, unordered_set<string> > g;
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        for(auto &rs : regions) {
            for(int i = 1; i < rs.size(); ++i)
                g[rs[0]].insert(rs[i]);
            //cout<<rs[0]<<endl;
        }
        vector<string> arr;
        for(auto &it : g) {
            //cout<<it.first<<endl;
            auto r = h(it.first, region1, region2);
            if(r.second == 2)
                return r.first;
        }
        //if(arr.size() == 1) return arr[0];
        return "";
    }
    
    pair<string, int> h(string cur, string &region1, string &region2) {
        vector<string> arr;
        if(cur == region1 || cur == region2) arr.push_back(cur);
        for(auto &n : g[cur]) {
            auto res = h(n, region1, region2);
            if(res.second == 2) return res;
            if(res.first.size() > 0)
                arr.push_back(res.first);
        }
        if(arr.size() >= 2) return {cur, 2};
        if(arr.size() == 1) return {arr[0], 1};
        return {"", 0};
    }
};