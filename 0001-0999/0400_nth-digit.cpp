//Link: https://leetcode.com/problems/nth-digit/ 
class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 9, len = 1, start = 1;
        while(cnt * len < n) {
            n -= cnt * len;
            cnt *= 10;
            ++len;
            start *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n-1)%len] - '0';
    }
};