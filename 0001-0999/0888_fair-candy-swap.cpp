//Link: https://leetcode.com/problems/fair-candy-swap/ 
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int diff = sumA - sumB;
        if( diff == 0 ) return {};
        unordered_set<int> m1;
        for( int i = 0; i<A.size(); i++ ){
            m1.insert(A[i]);
        }
        
        for( int i = 0; i<B.size(); i++ ){
            if( m1.count(B[i] + diff /2) )
                return {B[i] + diff /2, B[i]};
        }
        return {};
    }
};