//Link: https://leetcode.com/problems/4sum/ 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        for( int i  = 0; i< size -3; i++ ){
            if( i>0 && nums[i] == nums[i-1]) continue;
            for( int j = i+1; j< size-2; j++){
                if( j>i+1 && nums[j] == nums[j-1]) continue;
                if( nums[i] + nums[j] + nums[j+1] +nums[j+2] > target )break;
                int left = j+1;
                int right = size-1;
                while( left < right){
                    int total = nums[i] + nums[j] + nums[left] +nums[right];
                    while( total > target ) { right--;if( nums[right]!=nums[right+1])break;}
                    while( total < target ) {left++;if( nums[left]!=nums[left-1])break;}
                    if( total == target ){
                        ans.push_back({nums[i], nums[j], nums[left],nums[right]});
                        while(left<right){ right--;if( nums[right]!=nums[right+1])break;}
                        while(left<right){left++;if( nums[left]!=nums[left-1])break;}
                    }
                }
            }
        }
        return ans;
    }
};