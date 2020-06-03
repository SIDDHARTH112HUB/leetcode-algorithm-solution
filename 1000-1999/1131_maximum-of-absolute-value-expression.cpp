//Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/ 
class Solution {
public:
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
    
        /*res = a1[i] + a2[i]  - (a1[j] + a2[j] + j);
        res = a2[i] - a1[i] + (a1[j] - a2[j] - j);
        res = a1[i]- a2[i] - (a1[j] - a2[j] + j);
        res = -(a1[i] + a2[i]) + (a1[j] + a2[j] - j);
        */
        int b[4] = {0};
        int ans = 0;
        for(int i = 0; i < a1.size(); ++i) {
            int r1 = a1[i] + a2[i];
            int r2 = a1[i] - a2[i];
            if( i == 0){
                b[0] = r1 + i;
                b[1] = r2 - i;
                b[2] = r2 + i;
                b[3] = r1 - i;
                continue;
            }
            ans = max(ans, r1 - b[0] + i);
            ans = max(ans, -r2 + b[1] + i);
            ans = max(ans, r2 - b[2] + i);
            ans = max(ans, -r1 + b[3] + i);
            b[0] = min(b[0], r1 + i);
            b[1] = max(b[1], r2 - i);
            b[2] = min(b[2], r2 + i);
            b[3] = max(b[3], r1 - i);
        }
        return ans;
    }
};