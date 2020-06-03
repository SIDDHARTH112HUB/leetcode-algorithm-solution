//Link: https://leetcode.com/problems/reducing-dishes/ 
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int idx = 1;
        int sum = 0;
        int ans = 0;
        for(int n : satisfaction) {
            if(n >= 0) {
                sum += n;
                ans += n * idx;
                ++idx;
            }
        }
        
        vector<int> arr;
        idx = 1;
        vector<int > dp(satisfaction.size() + 1, INT_MIN);
        dp[0] = 0;
        for(int n : satisfaction) {
            if(n < 0) {
                for(int cnt = idx - 1; cnt>=0; --cnt)
                    dp[cnt+1] = max(dp[cnt+1], dp[cnt] + n * (cnt+1) + sum);
                ++idx;
                
            }
        }
        int mx = 0, mi = 0;
        for(int i = 0; i < dp.size(); ++i) {
            if(dp[i] > mx) {
                mx = dp[i];
            }
        }
        //cout<<mx<<endl;
        return ans + mx;
    }
};