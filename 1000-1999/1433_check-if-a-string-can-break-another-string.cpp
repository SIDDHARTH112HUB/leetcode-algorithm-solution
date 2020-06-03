//Link: https://leetcode.com/problems/check-if-a-string-can-break-another-string/ 
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        string rs1 = s1;
        reverse(rs1.begin(), rs1.end());
        string rs2 = s2;
        reverse(rs2.begin(), rs2.end());
        bool ans1 = true, ans2 = true;
        for(int i = 0; i < rs1.size(); ++i) {
            if(rs1[i] < rs2[i]) {
                ans1 = false;
            }
            if(rs2[i] < rs1[i]) {
                ans2 = false;
            }
        }
        return ans1 || ans2;
    }
};