//Link: https://leetcode.com/problems/4-keys-keyboard/ 
class Solution {
public:
    map<int, int> m;
    int maxA(int N) {
        if(m.count(N)) return m[N];
        int res = N;
        for(int i = 1; i < N - 2; ++i) {
            res = max(res, maxA(i) * (N - i - 1));
        }
        return m[N] = res;
    }
};