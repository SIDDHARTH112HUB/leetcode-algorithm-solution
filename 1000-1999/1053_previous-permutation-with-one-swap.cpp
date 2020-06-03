//Link: https://leetcode.com/problems/previous-permutation-with-one-swap/ 
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A.size() <= 1) return A;
        for(int i = A.size()-1; i > 0; --i) {
            if(A[i-1] > A[i]){
                auto it = lower_bound(A.begin()+i, A.end(), A[i-1]);
                --it;
                if(*it != A[i])
                    swap(A[i-1], *it);
                else
                    swap(A[i-1], A[i]);
                break;
            }
            
        }
        return A;
    }
};