//Link: https://leetcode.com/problems/destination-city/ 
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m;
        set<string> s;
        for(auto &path : paths) {
            ++m[path[0]];
            s.insert(path[0]);
            s.insert(path[1]);
        }
        for(auto p : s) {
            if(m.count(p) == 0)
                return p;
        }
        return "";
    }
};