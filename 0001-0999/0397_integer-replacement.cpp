//Link: https://leetcode.com/problems/integer-replacement/ 
class Solution {
public:
    int low(int n) { return n & -n; }
    int integerReplacement(long long n) {
        int ans = 0;
        while(n > 1) {
            if(n % 2) {
                long long n1 = (n + 1)>>1;
                long long n2 = (n - 1)>>1;
                ans += 2;
                if(n1 == 1 || n2 == 1)
                    return ans;
                n = low(n1) > low(n2) ? n1 : n2;
            }else{
                n = n >> 1;
                ++ans;
            }
        }
        return ans;
    }
};