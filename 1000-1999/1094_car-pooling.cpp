//Link: https://leetcode.com/problems/car-pooling/ 
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for(auto &trip : trips) {
            m[trip[1]] += trip[0];
            m[trip[2]] -= trip[0];
        }
        int cur = 0;
        for(auto &it : m){
            cur += it.second;
            if(cur > capacity)
                return false;
        }
        return true;
    }
};