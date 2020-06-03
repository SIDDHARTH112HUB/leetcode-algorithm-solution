//Link: https://leetcode.com/problems/digit-count-in-range/ 
class Solution {
public:
    int countDigit(int n, int d) {
        if(n < 0) return 0;
        long long ans = 0;
        for(long long m = 1; m <=n; m*=10) {
            int a = n / m, b = n % m;
            ans += (a + 9 - (d == 0?10:d)) / 10 * m + ( a % 10 == d ? b + 1 : 0);
        }
        return ans;
    }
    int digitsCount(int d, int low, int high) {
        return countDigit(high, d) - countDigit(low - 1, d);
    }
    
};