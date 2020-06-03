//Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/ 
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        long long n = 1;
        int cnt = 1;
        unordered_set<int> m;
        while(true) {
            if(n % K == 0)
                return cnt;
            if(m.count(n))
                return -1;
            m.insert(n);
            n = (n * 10 + 1) % K;
            ++cnt;
        }
        return -1;
    }
};