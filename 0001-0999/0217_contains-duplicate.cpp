//Link: https://leetcode.com/problems/contains-duplicate/ 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n : nums){
            if(m[n]++ > 0)
                return true;
        }
        return false;
    }
};