//Link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/ 
class Solution {
public:
    int findIntegers(int num) {
        string s;
        while(num > 0){
            s += (num & 1) ? '1' : '0';
            num >>= 1;
        }
        int n = s.size();
        int z[n] = {0} ,o[n] = {0};
        z[0] = o[0] = 1;
        for(int i = 1; i < n; ++i){
            z[i] = z[i-1] + o[i-1];
            o[i] = z[i-1];
        }
        int ans = o[n-1] + z[n-1];
        n -= 2;
        while(n >= 0) {
            if(s[n] == s[n+1] && s[n] == '1') break;
            if(s[n] == s[n+1] && s[n] == '0') ans -= o[n];
            --n;
        }
        return ans;
    }
};