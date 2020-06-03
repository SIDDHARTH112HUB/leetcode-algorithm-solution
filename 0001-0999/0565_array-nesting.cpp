//Link: https://leetcode.com/problems/array-nesting/ 
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int idx = i;
            int cnt = 0;
            while( nums[idx] != -1){
                int tmp = nums[idx];
                nums[idx] = -1;
                idx = tmp;
                ++cnt;
            }
            ans = max( ans, cnt);
        }
        return ans;
    }
};