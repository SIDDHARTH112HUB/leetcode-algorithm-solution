//Link: https://leetcode.com/problems/132-pattern/ 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> s;
        int third = INT_MIN;
        int size = nums.size();
        for(int i = size - 1; i >= 0; --i) {
            int n = nums[i];
            if(n < third) return true;
            while(s.size() && n > s.back()) {
                third = s.back(); s.pop_back();
            }
            s.push_back(n);
        }
        return false;
    }
};