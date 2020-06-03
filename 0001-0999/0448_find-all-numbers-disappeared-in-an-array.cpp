//Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/ 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int N = nums.size();
        if( N == 0 ) return ans;
        nums.push_back(nums[0]);
        N++;
        for( int i = 0; i< N; i++ ){
            int val = nums[i];
            while( val < N && val != nums[val]){
                int tmp = nums[val];
                nums[val] = val;
                val = tmp;
            }
        }
        for( int i = 1; i<N; i++ ){
            if( i != nums[i])
                ans.push_back(i);
        }
        return ans;
    }
};