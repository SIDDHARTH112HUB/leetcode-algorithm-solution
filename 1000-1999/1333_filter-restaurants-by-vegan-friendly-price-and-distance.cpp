//Link: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/ 
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int> > ans;
        
        for(auto &r : restaurants) {
            if(veganFriendly && r[2] == 0) continue;
            if(r[3] > maxPrice) continue;
            if(r[4] > maxDistance) continue;
            ans.push_back(r);
        }
        sort(ans.begin(), ans.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] > b[1];
        });
        vector<int> res;
        for(auto &r : ans)
            res.push_back(r[0]);
        return res;
    }
};