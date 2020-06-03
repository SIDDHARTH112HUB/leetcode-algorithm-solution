//Link: https://leetcode.com/problems/divide-array-into-increasing-sequences/ 
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        map<int, int> m;
        int maxCount = 0;
        for(int n : nums){
            ++m[n];
            maxCount = max(maxCount, m[n]);
        }
        if(maxCount * K > nums.size()) return false;
        return true;
    }
};