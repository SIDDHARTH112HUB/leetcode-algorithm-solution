//Link: https://leetcode.com/problems/3sum-closest/ 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for( int i = 0; i<nums.size()-2; i++ ){
            int k = nums.size()-1;
            int j = i+1;
            while(j<k){
                int total = nums[i]+nums[j]+nums[k];
                ans = abs(total-target) < abs( ans - target ) ?total : ans;
                if( total > target ) k--;
                else j++;
            }
        }
        return ans;
    }
};