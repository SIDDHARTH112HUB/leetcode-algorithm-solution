//Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/ 
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        if( nums.size() == 0 ) return 0;
        sort( nums.begin(), nums.end() );
        int left = 0, right = nums.back()-nums[0];
        while( left < right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            int j = 1;
            for( int i = 0; i< nums.size(); i++){
                while( j<nums.size() && nums[j]-nums[i]<=mid)++j;
                cnt += j-i-1;
            }
            if( cnt < k )
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};