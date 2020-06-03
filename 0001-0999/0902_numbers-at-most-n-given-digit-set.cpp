//Link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/ 
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string ns = to_string(N);
        int n = ns.size();
        int ans = 0;
        for( int i = 1; i<n; i++)
            ans += pow(D.size(), i);
        
        for( int i = 0; i < n; i++){
            bool prefix = false;
            for( int j = 0; j < D.size(); j++){
                if( D[j][0] < ns[i]){
                    ans += pow(D.size(), n-i-1);
                }else if( D[j][0] == ns[i] ){
                    prefix = true;
                    break;
                }
            }
            if( !prefix) return ans;
        }
        return ans + 1;
    }
};