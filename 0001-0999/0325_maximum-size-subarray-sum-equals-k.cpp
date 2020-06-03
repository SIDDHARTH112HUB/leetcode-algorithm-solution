//Link: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/ 
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int n = nums[i];
            sum += n;
            if(m.count(sum - k))
                ans = max(ans, i - m[sum - k]);
            if(m.count(sum) == 0)
                m[sum] = i;
        }
        return ans;
    }
};