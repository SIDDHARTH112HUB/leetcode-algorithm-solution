//Link: https://leetcode.com/problems/total-hamming-distance/ 
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for(int i = 0; i<32; i++){
            int count = 0;
            for( int n : nums){
                count += (n>>i)&1;
            }
            ans += count * (size -count);
        }
        return ans;
    }
};