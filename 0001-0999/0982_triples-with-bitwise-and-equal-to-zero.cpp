//Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/ 
class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int m[2<<16];
        memset(m, -1, sizeof(m));
        for( auto a : A){
            for( auto b : A){
                int x = a &b;
                if( m[x] == -1 ){
                    m[x] = 0;
                    for( auto c : A)
                        if( ( x & c) == 0 )
                            m[x]++;
                }
                ans += m[x];
            }
        }
        return ans;
    }
};