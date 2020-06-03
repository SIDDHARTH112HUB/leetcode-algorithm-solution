//Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/ 
class Solution {
public:
    unordered_map<int, int> mem;
    int numOfArrays(int n, int m, int k) {
        if(k > m) return 0;
        return h(0, n, m, k);
    }
    int h(int s, int n, int m, int k) {
        if(k > m) return 0;
        if(k > n) return 0;
        if(n == 0) {
            return k == 0;
        }
        int hs = (s<<16) | (n << 8) | k;
        if(mem.count(hs))return mem[hs];
        int res = 0;
        for(int i = 1; i<= m; ++i){
            res += h(max(s, i), n - 1, m, k - (i > s));
            res %= 1000000007;
        }
        return mem[hs] = res;
    }
};