//Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/ 
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto &d : dominoes) {
            int a = d[0];
            int b = d[1];
            int ab = a*10 +b;
            int ba = b *10 + a;
            if(m.count(ab) || m.count(ba))
                ans += m[ab];
            ++m[ab];
            if(ab != ba)
                ++m[ba];
        }
        return ans;
    }
    
};