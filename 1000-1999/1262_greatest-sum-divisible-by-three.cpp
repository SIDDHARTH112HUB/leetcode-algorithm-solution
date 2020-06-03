//Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 3 == 0) return sum;
        vector<vector<int> > arr(3);
        for(auto n : nums) {
            arr[n%3].push_back(n);
        }
        sort(arr[1].begin(), arr[1].end());
        sort(arr[2].begin(), arr[2].end());
        int md = sum % 3;
        int ans = 0;
        if(md == 2) {
            if(arr[2].size() > 0)
                ans = max(ans, sum - arr[2][0]);
            if(arr[1].size() > 1)
                ans = max(ans, sum - arr[1][0] - arr[1][1] );
        }
        if(md == 1) {
            if(arr[2].size() > 1)
                ans = max(ans, sum - arr[2][0] - arr[2][1]);
            if(arr[1].size() > 0)
                ans = max(ans, sum - arr[1][0] );
        }
        return ans;
    }
};