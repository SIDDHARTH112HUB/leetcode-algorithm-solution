//Link: https://leetcode.com/problems/pizza-with-3n-slices/ 
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> a(slices);
        a.insert(a.end(), slices.begin(), slices.end());

        vector<vector<int>> f(2 * n + 1, vector<int>(2 * n + 1, 0));
        for (int i = 1; i < 2 * n - 1; i++)
            f[i - 1][i + 1] = a[i];

        for (int len = 6; len <= n; len += 3)
            for (int i = 0; i < 2 * n - len + 1; i++) {
                int j = i + len - 1;

                for (int k = i + 2; k <= j - 3; k += 3)
                    f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);

                for (int k = i + 1; k <= j - 1; k += 3)
                    f[i][j] = max(f[i][j], f[i + 1][k - 1] + a[k] + f[k + 1][j - 1]);
            }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[i][i + n - 1]);

        return ans;
    }
};
