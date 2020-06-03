//Link: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ 
class Solution {
public:
    string bin(int n) {
        string ans;
        while(n > 0){
            ans += (n & 1)? '1' : '0';
            n >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string S, int N) {
        
        for(int i = N; i >= 1; --i) {
            if(S.find(bin(i)) == S.npos) return false;
        }
        return true;
    }
};