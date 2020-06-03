//Link: https://leetcode.com/problems/find-the-derangement-of-an-array/ 
class Solution {
public:
    int findDerangement(int n) {
        if(n <= 3) return n - 1;
        long long a = 0, b = 1, c = 2;
        long long i = 4;
        while(i <= n) {
            a = b;
            b = c;
            c = ((a + b) * (i - 1)) % 1000000007;
            ++i;
        }
        return c;
    }
};
