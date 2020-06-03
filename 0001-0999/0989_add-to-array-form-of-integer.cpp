//Link: https://leetcode.com/problems/add-to-array-form-of-integer/ 
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int c = 0;
        int i = 0;
        while( K > 0  || c > 0){
            A[i] += K % 10 + c ;
            c = (A[i] / 10);
            A[i] %= 10;
            K /= 10;
            i++;
            if( i == A.size() && ( c > 0 || K > 0 ) )
                A.push_back(0);
        }
        reverse(A.begin(), A.end());
        return A;
    }
};