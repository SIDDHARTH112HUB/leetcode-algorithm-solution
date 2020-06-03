//Link: https://leetcode.com/problems/sort-colors/ 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if( nums.size() == 0 ) return;
        int cnt[3] = {0,0,0};
        for(int &n:nums)
            ++cnt[n];
        int idx = 0;
        for( int i = 0; i<3;i++){
            while(cnt[i]-->0)
                nums[idx++] = i;
        }
    }
};