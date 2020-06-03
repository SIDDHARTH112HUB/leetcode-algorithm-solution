//Link: https://leetcode.com/problems/count-primes/ 
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n+1, true);
        int ans = 0;
        for(int i = 2; i<n ; i++){
            if( vec[i] == false)
                continue;
            ans++;
            for(int j = i*i; j<=n;j+=i){
                vec[j] = false;
            }
        }
        return ans;
    }
};