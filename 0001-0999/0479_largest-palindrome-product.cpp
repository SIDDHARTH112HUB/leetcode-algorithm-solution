//Link: https://leetcode.com/problems/largest-palindrome-product/ 
class Solution {
public:
    int largestPalindrome(int n) {
        long l = pow(10, n - 1), r = pow(10, n) - 1;
        for(long num = r; num >=l; --num) {
            string str = to_string(num);
            long p = stol(str + string(str.rbegin(), str.rend()));
            for(long j = r; j * j >= p; --j) {
                if( p% j == 0) return p%1337;
            }
        }
        return 9;
    }
};