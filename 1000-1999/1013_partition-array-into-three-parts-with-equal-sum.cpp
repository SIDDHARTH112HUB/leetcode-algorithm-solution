//Link: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/ 
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum % 3) return false;
        int n = 0;
        int cnt = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(n + A[i] == sum / 3) {
                n = 0;
                ++cnt;
            }else
                n += A[i];
        }
        return cnt == 3 && n == 0;
    }
};