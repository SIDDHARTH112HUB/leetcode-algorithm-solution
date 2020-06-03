//Link: https://leetcode.com/problems/super-palindromes/ 
class Solution {
public:
    
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L), r = stoll(R);
        int ans = 0;
        for( int i = 0; i<=100000; i++){
            for( int p = 0; p < 2; p++){
                if( i >= 10000 && p == 0 ) continue;
                long long n = i, t = i;
                if( p == 1) t/=10;
                while(t>0){
                    n =  n* 10 + t%10;
                    t /= 10;
                }
                n = n * n;
                if( n < l || n > r) continue;
                string s = to_string(n);
                bool ok = true;
                for( int j = 0; j < s.size()/2; j++){
                    if( s[j] != s[s.size()-j-1]){
                        ok = false;
                        break;
                    }
                        
                }
                if( ok )
                    ans++;
            }
        }
        return ans;
    }
};