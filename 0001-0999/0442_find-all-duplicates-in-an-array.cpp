//Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/ 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans;
        if( N == 0 ) return ans;
        nums.push_back(nums[0]);
        nums[0] = 0;
        N++;
        for( int i = 1; i<N; i++ ){
            while( nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for( int i = 1; i<N; i++ ){
            if( nums[i] != i )
                ans.push_back(nums[i]);
        }
        return ans;
    }
};