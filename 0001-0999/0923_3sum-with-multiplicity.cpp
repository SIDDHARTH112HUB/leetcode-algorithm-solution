//Link: https://leetcode.com/problems/3sum-with-multiplicity/ 
class Solution {
public:
    long long M = 1000000007;
    
    int threeSumMulti(vector<int>& A, int target) {
        long long f[101] = {0};
        for( int a : A )
            ++f[a];
        long long ans = 0;
        for( int i = 0; i<=100; i++){
            for( int j = i; j<=100 ; j++){
                for(int k = j; k <= 100; k++){
                    if( i+j+k != target )continue;
                    if( i < j  && j < k )
                        ans += (f[i]*f[j]*f[k])%M;
                    else if( i < j && j == k )
                        ans += (f[i]*f[j]*(f[k]-1)/2 )%M;
                    else if( i == j && j < k )
                        ans += (f[i]*(f[j]-1)*f[k]/2 )%M;
                    else if( i == j && j == k ){
                        ans += (f[i]*(f[j]-1) *(f[k]-2) /6) %M;
                    }
                    
                }
                
            }
        }
        ans %= M;
        return ans;
    }
};