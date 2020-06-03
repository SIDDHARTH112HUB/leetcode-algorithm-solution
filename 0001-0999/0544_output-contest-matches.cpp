//Link: https://leetcode.com/problems/output-contest-matches/ 
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ans(n);
        for(int i = 1; i <=n; ++i)
            ans[i-1] = to_string(i);
        while(n > 1) {
            int mid = (n-1) / 2;
            for(int i= 0; i <= mid; ++i) {
                ans[i] = "(" + ans[i] + "," + ans[n - 1 - i] +")";
            }
            n = mid + 1;
        }
        return ans[0];
    }
};