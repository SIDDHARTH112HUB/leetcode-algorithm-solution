//Link: https://leetcode.com/problems/tag-validator/ 
class Solution {
public:
    bool isValid(string code) {
        regex cdata("<!\\[CDATA\\[.*?\\]\\]>"), tag("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, cdata, "c");
        string prv;
        while(prv != (code=regex_replace(code, tag, "t")))prv = code;
        return code == "t";
    }
};