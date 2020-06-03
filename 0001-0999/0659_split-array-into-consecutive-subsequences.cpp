//Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/ 
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if( nums.size()  <= 2 ) return false;
        int size = nums.back();
        unordered_map<int, int> freq, req;
        for( int n : nums ){
            ++freq[n];
        }
        for( int n : nums){
            if( freq[n] == 0 ) continue;
            if( req[n] > 0 ){
                --req[n];
                ++req[n+1];
            }else if( freq[n+1] > 0 && freq[n+2] > 0 ){
                --freq[n+1];
                --freq[n+2];
                ++req[n+3];
            }else
                return false;
            --freq[n];
        }
        return true;
    }
};