//Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ 
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        for(int i = 1; i <= 6; ++i) {
            int cnt = 0;
            int total = 0;
            for(int j = 0; j < A.size(); ++j) {
                if(A[j] == i && B[j] == i) continue;
                if(A[j] != i && B[j] != i){
                   cnt = -1;
                    break;
                }
                ++total;
                if(A[j] == i)
                    ++cnt;
            }
            if(cnt >= 0)
                ans = min(ans, min(cnt, total - cnt));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};