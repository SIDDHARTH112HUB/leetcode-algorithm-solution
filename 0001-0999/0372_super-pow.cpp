//Link: https://leetcode.com/problems/super-pow/ 
class Solution {
public:
    vector<int> m;
    int superPow(int a, vector<int>& b) {
        int p = 1;
        a %= 1337;
        for(int i = 0; i <= 9; ++i) {
            m.push_back(p);
            p *= a;
            p %= 1337;
        }
        long long res = 1;
        for(int i = 0; i < b.size(); ++i) {
            long long p = 1;
            for(int i = 0; i <10; ++i) {
                p *= res;
                p %= 1337;
            }
            res =(p * m[b[i]]) % 1337;
        }
        return res;
    }
};