//Link: https://leetcode.com/problems/shortest-way-to-form-string/ 
class Solution {
public:
    int shortestWay(string source, string target) {
        map<int, vector<int> > m;
        for(int i = 0; i < source.size(); ++i) {
            m[source[i]].push_back(i);
        }
        int ans = 1, i = 0, j = 0;
        while(i < target.size()) {
            int c = target[i];
            if(m[c].size() == 0) return -1;
            auto it = lower_bound(m[c].begin(), m[c].end(), j);
            
            if(it == m[c].end()) {
                j = 0;
                ++ans;
            }else{
                ++i;
                j = *it + 1;
            }
        }
        return ans;
    }
};