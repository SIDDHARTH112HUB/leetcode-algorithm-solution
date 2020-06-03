//Link: https://leetcode.com/problems/ternary-expression-parser/ 
class Solution {
public:
    string parseTernary(string expression) {
        int idx = 0;
        return helper(expression, idx);
    }
    
    string helper(string &e, int &idx) {
        int srcIdx = idx;
        if(e[idx + 1] == '?') {
            auto T = helper(e, idx += 2);
            auto F = helper(e, ++idx);
            return e[srcIdx] == 'T' ? T : F;
        }
        return string(1, e[idx++]);
    } 
};