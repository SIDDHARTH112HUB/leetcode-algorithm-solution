//Link: https://leetcode.com/problems/sum-of-subarray-minimums/ 
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        vector<pair<int, int> > stk;
        stk.push_back({0, -1});
        long long ans = 0;
        for(int i = 0; i <= A.size(); ++i) {
            int n =((i == A.size()) ? 0 : A[i]);
            while(stk.back().first > n){
                auto p = stk.back();
                int idx = p.second;
                int n1 = p.first;
                stk.pop_back();
                int l = idx - stk.back().second;
                int r = i - idx;
                ans = (ans + (r * l * A[idx]) % M) % M;
            }
            stk.push_back({n, i});
        }
        return ans;
    }
};