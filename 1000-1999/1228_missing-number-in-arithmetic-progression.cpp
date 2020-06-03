//Link: https://leetcode.com/problems/missing-number-in-arithmetic-progression/ 
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int d1 = arr[1] - arr[0];
        int d2 = arr.back() - arr[arr.size()-2];
        if(abs(d1) > abs(d2)) d1 = d2;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] - arr[i-1] != d1) {
                return arr[i] - d1;
            }
        }
        return 0;
    }
};