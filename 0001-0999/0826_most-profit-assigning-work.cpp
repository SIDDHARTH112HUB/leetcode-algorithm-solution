//Link: https://leetcode.com/problems/most-profit-assigning-work/ 
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        map<int, int> m;
        int ans = 0;
        for(int i=0; i<D.size(); i++ )
            m[D[i]] = max(m[D[i]], P[i]);
        for(auto it = next(m.begin()); it != m.end(); ++it)
            it->second = max( it->second, prev(it)->second );
        for(int w: W){
            auto it = m.upper_bound(w);
            ans += (it == m.begin() ? 0: prev(it)->second);
        }
        return ans;
    }
};