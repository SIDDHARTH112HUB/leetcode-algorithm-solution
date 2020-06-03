//Link: https://leetcode.com/problems/binary-prefix-divisible-by-5/ 
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int ans = 0;
        vector<bool> v;
        for(auto n : A){
            ans = (ans << 1) | n;
            v.push_back(ans % 5 == 0);
            ans %= 5;
        }
        return v;
    }
};