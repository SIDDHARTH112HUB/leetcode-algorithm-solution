//Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/ 
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int, int> m;
        int cur = 0;
        int ans = 0;
        int all = 0;
        for(int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i-1];
        }
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                for(int k = i; k < j; ++k) {
                    int b = arr[j] ^ arr[k];
                    int a = arr[k] ^ (i > 0 ? arr[i-1]: 0);
                    ans += a == b;
                }
            }
        }
        return ans;
    }
};