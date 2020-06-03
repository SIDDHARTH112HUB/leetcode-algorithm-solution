//Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ 
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = accumulate(weights.begin(), weights.end(), 0);
        while(l < r) {
            int mid = (l+r) / 2;
            int total = 0;
            int d = 1;
            for(int w  : weights) {
                if (w > mid) {
                    d = INT_MAX;
                    break;
                }
                if(total + w <= mid) {
                    total += w;
                }else {
                    total = w;
                    ++d;
                }
            }
            if(d >D)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};