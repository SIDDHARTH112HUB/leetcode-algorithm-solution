//Link: https://leetcode.com/problems/increasing-subsequences/ 
class Solution {
public:
    set<vector<int> > ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> arr;
        f(nums, 0, arr);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void f(vector<int> &nums, int idx, vector<int> &arr) {
        if(idx >= nums.size() ){
            if(arr.size() >= 2)
                ans.insert(arr);
            return;
        }
        if((arr.size() == 0 || arr.back() <= nums[idx])) {
            arr.push_back(nums[idx]);
            f(nums, idx+1, arr);
            arr.pop_back();
        }
        f(nums, idx + 1, arr);
        
    }
};