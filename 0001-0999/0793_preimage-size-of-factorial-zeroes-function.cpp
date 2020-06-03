//Link: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/ 
class Solution {
public:
    int preimageSizeFZF(int K) {
        long long l = 0, r = INT_MAX;
        r *= 10;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            long long n = zeros(mid);
            if(n == K)
                return 5;
            else if(n > K)
                r = mid;
            else
                l = mid + 1;
        }
        return 0;
    }
    
    long long zeros(long long n) {
        return n == 0 ? 0 : n / 5 + zeros(n / 5);
    }
};