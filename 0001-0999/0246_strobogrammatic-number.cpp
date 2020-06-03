//Link: https://leetcode.com/problems/strobogrammatic-number/ 
class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<int, int> m;
        m['0'] = '0';
        m['1'] = '1';
        m['2'] = 2;
        m['3'] = 3;
        m['4'] = 4;
        m['5'] = 5;
        m['6'] = '9';
        m['7'] = 7;
        m['8'] = '8';
        m['9'] = '6';
        string ans;
        for(int i = 0; i < num.size(); ++i) {
            ans += m[num[i]];
        }
        reverse(ans.begin(), ans.end());
        return ans == num;
    }
};