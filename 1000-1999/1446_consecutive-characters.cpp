//Link: https://leetcode.com/problems/consecutive-characters/ 
class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            bool f = true;
            for(int j = i; j < s.size(); ++j ){
                if(s[j] != s[i]) {
                    f = false;
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};