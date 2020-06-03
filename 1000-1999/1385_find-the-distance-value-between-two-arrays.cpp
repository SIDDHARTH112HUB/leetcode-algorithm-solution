//Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/ 
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(auto n : arr1) {
            bool f = true;
            for(auto m : arr2) {
                if(abs(n - m) <= d) {
                    f = false;
                    break;
                }
            }
            if(f) ++ans;
        }
        return ans;
    }
};