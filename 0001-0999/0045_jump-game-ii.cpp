//Link: https://leetcode.com/problems/jump-game-ii/ 
class Solution {
public:
    int jump(vector<int>& nums) {
        if( nums.size() <= 1 ) return 0;
        int i = 0;
        int ans = 0;
        while( i < nums.size() -1){
            if( i + nums[i] >= nums.size() -1 )
                return ans+1;
            int maxStep = 0;
            int j = nums[i] + i;
            int cur = i;
            while( j > cur){
                if( maxStep < j + nums[j] ){
                    maxStep = j + nums[j];
                    i = j;
                }
                j--;
            }
            ans++;
        }
        return ans;
    }
};