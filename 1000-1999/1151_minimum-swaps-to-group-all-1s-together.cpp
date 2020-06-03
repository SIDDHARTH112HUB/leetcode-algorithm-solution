//Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/ 
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int total = 0;
        int ans = INT_MAX;
        for(int i = 0; i < data.size(); ++i){
            total += data[i];
            if(i > 0)
                data[i] += data[i-1];
        }
        if( total <= 1) return 0;
        for(int i = 0; i < data.size(); ++i) {
            if(i >= total - 1) {
                ans = min(ans, total - data[i] + (i >= total ? data[i-total] : 0));
            }
        }
        return ans;
    }
};