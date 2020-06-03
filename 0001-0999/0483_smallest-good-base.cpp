//Link: https://leetcode.com/problems/smallest-good-base/ 
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        long long l = 2, r = num - 1;
        long long m = log(num + 1) / log(2);
        for(long long i = m; i >= 2; --i) {
            long long l = 2;
            long long r = pow(num, 1.0 / (i - 1)) + 1;
            while(l < r) {
                long long mid = l + (r - l) / 2, sum = 0;
                for(int j = 0; j < i;++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num)
                    return to_string(mid);
                if(sum > num)
                    r = mid;
                else
                    l = mid + 1;
            }
            
        }
        return to_string(num - 1);
    }
};