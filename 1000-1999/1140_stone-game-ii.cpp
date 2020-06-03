//Link: https://leetcode.com/problems/stone-game-ii/ 
class Solution {
public:
    map<pair<int, int>, int > m;
    int stoneGameII(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (sum + helper(piles, 0, 1)) / 2;
    }
    
    int helper(vector<int>& piles, int idx, int M) {
        if(idx >= piles.size()) return 0;
        if(m.count( {idx, M})) return m[{idx, M}];
        int ans = INT_MIN;
        int x = -1;
        int sum = 0;
        for(int X = 1; X <= 2 *M && idx + X <= piles.size(); ++X ) {
            sum += piles[idx + X - 1];
            int res = helper(piles, idx + X, max(M, X));
            ans = max(ans, sum - res);
        }
        m[{idx, M}] = ans;
        return ans;
    }
};