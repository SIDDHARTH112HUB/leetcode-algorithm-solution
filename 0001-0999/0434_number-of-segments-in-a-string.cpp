//Link: https://leetcode.com/problems/number-of-segments-in-a-string/ 
class Solution {
public:
    int countSegments(string s) {
        int i = 0, ans = 0;
        while(i <s.size() && s[i] == ' ')
            ++i;
        while(i < s.size()){
            while(i <s.size() && s[i] != ' ')
                ++i;
            while(i <s.size() && s[i] == ' ')
                ++i;
            ++ans;
        }
        return ans;
    }
};