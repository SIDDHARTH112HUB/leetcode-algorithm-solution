//Link: https://leetcode.com/problems/toss-strange-coins/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, double> > m;
    double probabilityOfHeads(vector<double>& prob, int target){
        vector<double> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= prob.size(); ++i)
            for(int j = min(target, i); j >=0; --j)
                dp[j] = (j > 0 ? dp[j-1] : 0) * prob[i-1] + dp[j] * (1.0-prob[i-1]);
        return dp[target];
    }
    double probabilityOfHeads1(vector<double>& prob, int target, int idx = 0) {
        if(target == 0) {
            double p = 1.0;
            for(int i = idx; i < prob.size(); ++i) {
                p *= (1 - prob[i]);
            }
            return p;
        }
        
        if(idx >= prob.size()) return 0;
        if(m[idx].count(target) ) return m[idx][target];
        double p = 0;
        p += probabilityOfHeads1(prob, target, idx + 1) * (1- prob[idx] );
        p += probabilityOfHeads1(prob, target - 1, idx + 1) * prob[idx];
        m[idx][target] = p;
        return p;
    }
};