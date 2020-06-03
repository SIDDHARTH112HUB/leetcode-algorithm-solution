//Link: https://leetcode.com/problems/sort-array-by-parity/ 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for( int n: A ){
            if( n % 2)
                odd.push_back(n);
            else
                even.push_back(n);
        }
        for( int n : odd){
            even.push_back(n);
        }
        return even;
    }
};