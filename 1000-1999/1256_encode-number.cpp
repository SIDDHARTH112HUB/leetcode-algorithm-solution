//Link: https://leetcode.com/problems/encode-number/ 
class Solution {
public:
    string encode(int num) {
        num = num + 1;
        string ans;
        while(num > 0) {
            ans +=( (num & 1) + '0');
            num = num >> 1;
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};