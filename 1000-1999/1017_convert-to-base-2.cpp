//Link: https://leetcode.com/problems/convert-to-base-2/ 
class Solution {
public:
    string baseNeg2(int N) {
        if(N==0) return "0";
        string ans;
        long long n = 1;
        int sign = 1;
        while(N>0){
            if(N & n){
                N -= sign*n;
                ans+="1";
            }else
                ans+="0";
            sign *= -1;
            n = n << 1;       
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};