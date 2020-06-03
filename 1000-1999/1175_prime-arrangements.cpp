//Link: https://leetcode.com/problems/prime-arrangements/ 
class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int cnt = 0;
        for(int i = 0; i < p.size(); ++i) {
            if(p[i] <= n)
                ++cnt;
        }
        n -= cnt;
        int M = 1e9 + 7;
        long long ans = 1, ans2 = 1;
        for(long long i = 1; i <=n; ++i)
            (ans = ans * i) %= M;
        for(long long i = 1; i <=cnt; ++i)
            (ans2 = ans2 * i) %= M;
        ans *= ans2;
        ans %= M;
        return ans;
    }
};