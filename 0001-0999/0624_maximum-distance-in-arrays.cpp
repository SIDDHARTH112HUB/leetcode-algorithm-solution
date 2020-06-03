//Link: https://leetcode.com/problems/maximum-distance-in-arrays/ 
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.size() == 0) return 0;
        int mn = arrays[0][0], mx = arrays[0].back();
        int ans = INT_MIN;
        for(int i = 1; i < arrays.size(); ++i) {
            ans = max(ans, max(abs(arrays[i].back() - mn), abs(arrays[i][0] - mx)) );
            mx = max(mx, arrays[i].back());
            mn = min(mn, arrays[i][0]);
        }
        return ans;
    }
};