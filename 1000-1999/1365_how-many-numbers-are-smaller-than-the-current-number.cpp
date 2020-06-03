//Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(auto n :nums){
            int c = 0;
            for(auto m :nums){
                if(n > m) ++c;
            }
            ans.push_back(c);
        }
        return ans;
    }
};