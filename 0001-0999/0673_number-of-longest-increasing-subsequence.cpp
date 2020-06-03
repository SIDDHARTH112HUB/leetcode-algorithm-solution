//Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/ 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;
        vector<int> len(n, 1), cnt(n, 1);
        for(int i = 0; i < n; ++i){
            int a = nums[i];
            for(int j = 0; j < i; ++j) {
                int b = nums[j];
                if(a <=b ) continue;
                if(len[i] < len[j]+ 1){
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                    mx = max(mx, len[i]);
                }else if(len[i] == len[j] + 1){
                    cnt[i] += cnt[j];
                }
                
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(len[i] == mx) ans += cnt[i];
        }
        return ans;
    }
};