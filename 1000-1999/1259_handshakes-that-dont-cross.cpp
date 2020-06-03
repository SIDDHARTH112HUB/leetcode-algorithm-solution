//Link: https://leetcode.com/problems/handshakes-that-dont-cross/ 
class Solution {
public:
    int M = 1e9+7;
    unordered_map<int, int> m;
    int numberOfWays(int num_people) {
        m[1] = 1;
        return h(1, num_people);
    }
    
    long long h(int l, int r) {
        if(r - l == 1) return 1;
        if(l >= r) return 1;
        if((r-l) % 2 == 0) return 0;
        if(m.count(r-l)) return m[r-l];
        long long res = 0;
        for(int i = l + 1; i <= r; i += 2) {
            res += ( h(l + 1, i - 1) * h(i+1, r)) %M;
        }
        m[r-l] = res %M;
        return res %M;
    }
};