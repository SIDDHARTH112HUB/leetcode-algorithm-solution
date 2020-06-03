//Link: https://leetcode.com/problems/sliding-window-median/ 
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k / 2);
        vector<double> ans;
        for(int i = k; ; ++i) {
            ans.push_back((*mid + *prev(mid, 1 - k%2)) / 2.0 );
            if(i >= nums.size()) return ans;
            ms.insert(nums[i]);
            if(nums[i] < *mid) --mid;
            if(nums[i - k] <= *mid) ++mid;
            ms.erase(ms.lower_bound(nums[i-k]));
        }
        return ans;
    }
};