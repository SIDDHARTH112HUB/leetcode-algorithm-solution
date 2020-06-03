//Link: https://leetcode.com/problems/increasing-decreasing-string/ 
class Solution {
public:
    string sortString(string s) {
        map<char, int>  m;
        for(auto c :s)
            ++m[c];
        string ans;
        while(m.size()) {
            bool f = false;
            for(auto &it : m) {
                if(it.second > 0) {
                    ans += it.first;
                    --it.second;
                    f = true;
                }
            }
            for(auto it = m.rbegin(); it != m.rend(); ++it) {
                if(it->second > 0) {
                    ans += it->first;
                    --it->second;
                    f = true;
                }
            }
            if(!f) return ans;
        }
        return ans;
    }
    
};