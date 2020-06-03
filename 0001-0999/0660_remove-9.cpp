//Link: https://leetcode.com/problems/remove-9/ 
class Solution {
public:
    int newInteger(int n) {
        long long p = 1;
        long long sum = 0;
        while(n > 0) {
            sum += (n % 9) * p;
            n /= 9;
            p *= 10;
        }
        return sum;
    }
};