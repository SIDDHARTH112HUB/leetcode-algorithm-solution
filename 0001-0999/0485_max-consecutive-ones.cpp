//Link: https://leetcode.com/problems/max-consecutive-ones/ 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for(int n : nums){
            if(n == 1){
                ++cnt;
                ans = max(ans, cnt);
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};