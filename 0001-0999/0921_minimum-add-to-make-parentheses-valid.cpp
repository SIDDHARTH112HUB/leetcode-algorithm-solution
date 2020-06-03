//Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/ 
class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int ans = 0;
        for( char c : S ){
            if( c == '(')
                cnt++;
            else
                cnt--;
            if( cnt < 0 ){
                ans++;
                cnt++;
            }
        }
        return ans + cnt;
    }
};