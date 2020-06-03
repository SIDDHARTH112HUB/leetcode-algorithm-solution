//Link: https://leetcode.com/problems/largest-multiple-of-three/ 
class Solution {
public:
    string form(vector<int> &cnt) {
        string ans;
        for(int i = 9; i >= 0; --i) {
            for(int j = 0; j < cnt[i]; ++j) {
                ans += i + '0';
            }
        }
        if(ans.size() > 0 && ans[0] == '0') return "0";
        return ans;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        for(auto n : digits)
            ++cnt[n];
        int sum = accumulate(digits.begin(), digits.end(), 0);
        if(sum % 3 != 0) {
            for(int i = 1; i <=9; ++i) {
                if(cnt[i] > 0 && i % 3 == sum % 3) {
                    --cnt[i];
                    return form(cnt);
                }
            }
            int x = 3 - (sum % 3);
            int c = 2;
            for(int i = 1; i <= 9; ++i) {
                if(cnt[i] > 0 && i % 3 == x) {
                    int src = cnt[i];
                    cnt[i] -= min(src, c);
                    c -= src;
                    if( c <= 0)
                        return form(cnt);
                }
            }
            return "";
        }
        return form(cnt);
    }
};