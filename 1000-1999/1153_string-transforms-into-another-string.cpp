//Link: https://leetcode.com/problems/string-transforms-into-another-string/ 
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        unordered_map<int, int> m, m2;
        for(int i = 0; i < str1.size(); ++i) {
            int a = str1[i], b = str2[i];
            if(m.count(a) && m[a] != b)
                return false;
            m[a] = b;
            m2[b] = a;
        }
        return m2.size() < 26;
    }
};