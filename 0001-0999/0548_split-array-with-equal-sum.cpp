//Link: https://leetcode.com/problems/split-array-with-equal-sum/ 
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        int n = nums.size();
        for(int j = 3; j < n -3; ++j) {
            unordered_set<int> s;
            for(int i = 1; i < j - 1; ++i) {
                if(nums[j - 1] - nums[i] == nums[i - 1])
                    s.insert(nums[i-1]);
            }
            for(int k = j + 1; k < n - 1; ++k) {
                if(nums[k-1] - nums[j] == nums.back() - nums[k])
                    if(s.count(nums[k-1] - nums[j]))
                        return true;
            }
        }
        return false;
    }
};