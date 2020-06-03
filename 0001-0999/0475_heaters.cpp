//Link: https://leetcode.com/problems/heaters/ 
class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int j = 0, res = 0, n = heaters.size();
        for(int house : houses) {
            int idx = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int d1 = idx == n ? INT_MAX : heaters[idx] - house ;
            int d2 = idx == 0 ? INT_MAX : house - heaters[idx-1];
            res = max(res, min(d1, d2));
        }
        return res;
    }
    /*
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int j = 0, res = 0;
        for(int house : houses) {
            while(j < heaters.size()-1 && abs(house - heaters[j]) >= abs(house-heaters[j+1]) ) {
                ++j;
            }
            res = max(res, abs(house - heaters[j]));
        }
        return res;
    }*/
};