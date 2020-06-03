//Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ 
class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string src = str;
        string str2 = str;
        for (auto c : str) {
            if(c < '9') {
                for (auto &c1 : str) {
                    if(c1 == c)
                        c1 = '9';
                }
                break;
            }
        }
        char a = '1';
        for (auto c : src) {
            if (c > a) {
                for (auto &c1 : str2) {
                    if(c1 == c)
                        c1 = a;
                }
                if(str2[0] == '0') {
                    str2 = src;
                    continue;
                }else
                    break;
                
            }
            if (a == '1')
                --a;
        }
        
        return stoi(str) - stoi(str2);
    }
};