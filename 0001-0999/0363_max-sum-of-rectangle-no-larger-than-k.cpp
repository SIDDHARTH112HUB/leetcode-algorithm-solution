//Link: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ 
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool revert = false;
        if (n > m) {
            swap(n, m);
            revert = true;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            vector<int> sum(m);
            for(int j = i; j < n; ++j) {
                for(int k = 0; k < m; ++k) {
                    if(revert)
                        sum[k] += matrix[j][k];
                    else
                        sum[k] += matrix[k][j];
                }
                set<int> s;
                s.insert(0);
                int cur = 0;
                for(int num : sum) {
                    cur += num;
                    auto it = s.lower_bound(cur - K);
                    if(it != s.end()) ans = max(ans, cur - *it);
                    s.insert(cur);
                }
            }
        }
        return ans;
    }
};