//Link: https://leetcode.com/problems/smallest-range-i/ 
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if( A.size() <= 1  ) return 0;
        int a = *max_element(A.begin(), A.end());
        int b = *min_element(A.begin(), A.end());
        if( abs(a-b) <= 2*K ) return 0;
        return abs(a-K - (b+K));
    }
};