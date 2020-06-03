//Link: https://leetcode.com/problems/hexspeak/ 
class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        string ans;
        while(n > 0) {
            int mod = n % 16;
            if(mod >= 2 && mod <=9) return "ERROR";
            if(mod == 0) {
                ans += 'O';
            }else if(mod == 1)
                ans += 'I';
            else
                ans += mod - 10 + 'A';
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};