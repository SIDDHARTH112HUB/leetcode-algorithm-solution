//Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ 
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> pre;
        vector<int> dp(arr.size() + 1, INT_MAX);
        pre[0] = -1;
        int ans = INT_MAX, sum = 0;
        map<int, pair<int, int> > cnt;
        for(int i = 0; i < arr.size(); ++i) {
            int n = arr[i];
            sum += n;
            if(pre.count(sum - target)) {
                if(dp[pre[sum-target] + 1] != INT_MAX) {
                    ans = min(ans, i - pre[sum-target] + dp[pre[sum-target] + 1]);
                }
                dp[i + 1] = min(dp[i], i - pre[sum-target]);
                
            }else{
                dp[i + 1] = dp[i];
            }
            pre[sum] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};