//Link: https://leetcode.com/problems/restore-the-array/ 
class Solution {
public:
    long long M = 1e9 + 7;
    unordered_map<long long, long long > m;
    int numberOfArrays(string s, int k) {
        return h(s, 0, s.size()-1, k);
    }
    
    long long h(string &s, int l, int r, int k) {
        if(l > r) return 1;
        if(s[l] == '0') return 0;
        if(l == r) {
            if(s[l] - '0' > k) return 0;
            return 1;
        }
        if(m.count(l)) return m[l];
        long long sum = 0;
        long long res = 0;
        for(int i = l; i <= r; ++i) {
            sum = sum * 10 + (long long)(s[i] - '0');
            if(sum > k)
                break;
            res += 1 * h(s, i + 1, r, k);
        }
        return m[l] = res % M;
    }
};