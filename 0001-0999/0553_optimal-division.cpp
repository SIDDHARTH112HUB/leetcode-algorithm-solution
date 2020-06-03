//Link: https://leetcode.com/problems/optimal-division/ 
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        
        
        if(nums.size() == 1) return to_string(nums[0]);;
        string r;
        for(int i = 1; i < nums.size(); ++i ) {
            r += to_string(nums[i]) + "/";
        }
        r.pop_back();
        if(nums.size() > 2){
            r = "("+r+")";
        }
        return to_string(nums[0]) + "/" + r;
    }
};