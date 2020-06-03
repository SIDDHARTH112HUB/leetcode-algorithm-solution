//Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/ 
class Solution {
public:
    long long M = 1000000007;
    unordered_map<int, unordered_map<int, int> > memo;
    long long numRollsToTarget(int d, int f, int target) {
        if(target > d * f) return 0;
        if(target < d) return 0;
        if( d == 1) return 1;
        if(memo[d].count(target)) return memo[d][target];
        long long res = 0;
        for(int i = 1; i <= f && i <= target; ++i) 
            (res += numRollsToTarget(d-1, f, target -i)) %= M;
        memo[d][target] = res;
        return res;
    }
};