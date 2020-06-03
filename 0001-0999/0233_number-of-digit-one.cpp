//Link: https://leetcode.com/problems/number-of-digit-one/ 
class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        for(long long m = 1; m <=n; m*=10) {
            int a = n / m, b = n % m;
            ans += (a + 8) / 10 * m + ( a % 10 == 1 ? b + 1 : 0);
        }
        return ans;
    }
};