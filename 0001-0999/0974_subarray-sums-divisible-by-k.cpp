//Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/ 
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        m[0] = 1;
        
        cout<<"Begin"<<endl;
        for( int a : A){
            sum = (sum + a%K +K) % K;
            
            /*if( sum % K == 0 ){
                ans++;
            }*/
            //ans += m[K - sum % K ];
            //ans += m[-(K-(sum % K) )];
            ans += m[sum ];
            ++m[sum];
            /*
            if( m[sum%K] == 0 )
                m[sum%K] = 1;
            else
                m[sum%K]+=m[sum%K];*/
        }
        return ans;
    }
};

