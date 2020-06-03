//Link: https://leetcode.com/problems/valid-triangle-number/ 
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = 0;
        if( size < 3 ) return 0;
        for( int i = size-1; i>1; i--){
            //int j = i+1, k = size-1;
            int a = nums[i];
            int k = 0, j = i-1;
            while(k<j){
                if( nums[j] + nums[k] > a){
                    ans += (j--)-k;
                }else
                    k++;
            }
        }
        return ans;
    }
};