//Link: https://leetcode.com/problems/max-consecutive-ones-iii/ 
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, k = 0;
        int ans = 0;
        while(j< A.size() && i <= j) {
            ans = max(j - i, ans);
            if(A[j] == 0) {
                k++;
                while(i < A.size() && k > K){
                    if(A[i] == 0)k--;
                    i++;
                }
            }
            j++;
        }
        ans = max(j - i, ans);
        return ans;
    }
};