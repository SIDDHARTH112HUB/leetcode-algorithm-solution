//Link: https://leetcode.com/problems/longest-harmonious-subsequence/ 
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto n : nums) ++cnt[n];
        int ans = 0;
        for(auto n :nums) {
            int cnt1 = cnt[n-1];
            int cnt2 = cnt[n+1];
            if(cnt1 > 0)
                ans = max(ans, cnt1 + cnt[n]);
            if(cnt2 > 0)
                ans = max(ans, cnt2 + cnt[n]);
        }
        return ans;
    }
};