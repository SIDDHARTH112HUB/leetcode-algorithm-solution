//Link: https://leetcode.com/problems/minimize-rounding-error-to-meet-target/ 
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        map<int, float> dp;
        dp[0] = 0;
        for(int i = 0; i < prices.size(); ++i) {
            map<int, float> tmp;
            float price = stod(prices[i]);
            for(auto &it : dp) {
                int cur = it.first + floor(price);
                float diff = it.second + fabs(price - floor(price));
                if(cur <= target && (tmp.count(cur) == 0 || diff < tmp[cur])) {
                    tmp[cur] = diff;
                }
                cur = it.first + ceil(price);
                diff = it.second + fabs(price - ceil(price));
                if(cur <= target && (tmp.count(cur) == 0 || diff < tmp[cur])) {
                    tmp[cur] = diff;
                }
            }
            dp = tmp;
        }
        if(dp.count(target) == 0) return "-1";
        stringstream stream;
        stream << fixed << setprecision(3) << dp[target];
        string s = stream.str();
        return s;
    }
};