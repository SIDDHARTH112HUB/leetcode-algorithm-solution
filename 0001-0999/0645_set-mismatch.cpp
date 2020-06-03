//Link: https://leetcode.com/problems/set-mismatch/ 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        nums.push_back(nums[0]);
        nums[0] = 0;
        for(int i = 1; i < nums.size(); ++i) {
            while(nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for(int i = 1; i < nums.size(); ++i) 
            if(nums[i] != i) 
                return {nums[i], i};
        return {};
    }
};