//Link: https://leetcode.com/problems/minimum-time-difference/ 
class Solution {
public:
    int getTime(string &str) {
        return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + str[4] - '0';
    }
    int mx = 24 * 60;
    set<int> s;
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        s.insert(getTime(timePoints[0]));
        for(int i = 1; i < timePoints.size(); ++i) {
            int t = getTime(timePoints[i]);
            auto it = s.upper_bound(t);
            if(it == s.end()){
                ans = min(ans, min(abs(t - *s.begin()), mx - abs(t - *s.begin())));
                --it;
            }
            ans = min(ans, min(abs(t - *it), mx - abs(t - *it)));
            it = s.upper_bound(t);
            if(it == s.begin()) {
                it = s.end();
            }
            --it;
            ans = min(ans, min(abs(t - *it), mx - abs(t - *it)));
            s.insert(t);
        }
        return ans;
    }
};