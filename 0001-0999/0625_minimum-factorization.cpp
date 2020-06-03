//Link: https://leetcode.com/problems/minimum-factorization/ 
class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        string res = "";
        for (int k = 9; k >= 2; --k) {
            while (a % k == 0) {
                res = to_string(k) + res;
                a /= k;
            }
        }
        if (a > 1) return 0;
        long long num = stoll(res);
        return num > INT_MAX ? 0 : num;
    }
};