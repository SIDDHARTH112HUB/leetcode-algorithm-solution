//Link: https://leetcode.com/problems/odd-even-jump/ 
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        if(A.size() == 0) return 0;
        bool dp[A.size()][2];
        memset(dp, 0, sizeof(dp));
        map<int, int> m;
        reverse(A.begin(), A.end());
        dp[0][false] = true;
        dp[0][true] = true;
        m[A[0]] = 0;
        int ans = 1;
        for(int i = 1; i < A.size(); ++i) {
            auto it = m.lower_bound(A[i]);
            if (it == m.end()){
                dp[i][true] = false;
            }else {
                dp[i][true] = dp[it->second][false];
                ans += dp[it->second][false];
            }
            if(it == m.begin() && it->first > A[i]) {
                dp[i][false] = false;
            }else{
                if(it == m.end() || it->first > A[i])
                    --it;
                dp[i][false] = dp[it->second][true];
            }
            m[A[i]] = i;
        }
        return ans;
    }
    
};