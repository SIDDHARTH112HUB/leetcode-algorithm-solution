//Link: https://leetcode.com/problems/monotone-increasing-digits/ 
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int j = str.size(); 
        for(int i = str.size() - 2; i >= 0; --i) {
            if(str[i]  <= str[i+1]) continue;
            str[i]--;
            j = i+1;
        }
        for(int i = j; i < str.size(); ++i) {
            str[i] = '9';
        }
        return stoi(str);
    }
};