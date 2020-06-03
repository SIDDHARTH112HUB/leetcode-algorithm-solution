//Link: https://leetcode.com/problems/student-attendance-record-i/ 
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for(int i = 0; i < s.size(); ++i) {
            A += s[i] == 'A';
            L = s[i] == 'L' ? L + 1 : 0;
            if(L > 2) return false;
        }
        return A <= 1;
    }
};