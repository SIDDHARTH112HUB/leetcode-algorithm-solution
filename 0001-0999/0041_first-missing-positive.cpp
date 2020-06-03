//Link: https://leetcode.com/problems/first-missing-positive/ 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        if( N == 0 ) return 1;
        nums.push_back(nums[0]);
        N++;
        for( int i = 0; i<nums.size(); i++){
            int target = nums[i];
            while(target>= 0&&target < N && target != nums[target]){
                int new_tar = nums[target];
                nums[target] = target;
                target = new_tar;
            }
            
        }
        for( int i = 1; i<nums.size();i++){
            if( i != nums[i] )
                return i;
        }
        return N;
    }
};