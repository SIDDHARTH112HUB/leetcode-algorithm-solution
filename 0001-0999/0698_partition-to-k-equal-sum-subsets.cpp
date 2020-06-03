//Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ 
class Solution {
public:
    bool fun(vector<int>& nums, int idx, int sum){
        if( sum == 0 ){
            return true;
        }
        for( int i = 0; i<nums.size(); i++){
            if( nums[i] == 0 )
                continue;
            if( sum - nums[i]>=0 ){
                int tmp = nums[i];
                nums[i] = 0;
                if( fun(nums, i, sum-tmp ) ){
                    return true;
                }
                nums[i] = tmp;
            }else{
                return false;
            }
        }
        return false;   
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for( int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum /= k;
        for(int  i= 0; i<k; i++){
            if(!fun(nums, 0, sum)){
                return false;
            }
        }
        return true;
    }
};