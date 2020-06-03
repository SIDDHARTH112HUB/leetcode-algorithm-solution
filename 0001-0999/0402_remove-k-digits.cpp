//Link: https://leetcode.com/problems/remove-k-digits/ 
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(auto c : num) {
            while(ans.size() && ans.back() > c && k > 0) {
                ans.pop_back();
                --k;
            }
            if(c > '0' || ans.size() > 0)
                ans += c;
        }
        while(ans.size() && k-- > 0)
            ans.pop_back();
        return ans == "" ? "0" : ans;
    }
};