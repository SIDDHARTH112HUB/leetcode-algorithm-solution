//Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int > > arr;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j)
                arr.push_back({nums[i][j], i});
        }
        sort(arr.begin(), arr.end());
        int e = 0, b = 0, k = 0;
        vector<int> cnt(nums.size());
        vector<int> ans;
        while(e < arr.size()) {
            if(cnt[arr[e++].second]++ == 0) ++k;
            while(k >= nums.size()) {
                int l = arr[b].first, r = arr[e- 1].first;
                if(ans.size() == 0 || r - l < ans[1] - ans[0]) {
                    ans = {l, r};
                }
                if(--cnt[arr[b++].second] == 0) --k;
            }
        }
        return ans;
    }
};