//Link: https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/ 
class Solution {
public:
    int countLetters(string S) {
        int same = 1, ans = 0;
        S+= ' ';
        for(int i = 1; i < S.size(); ++i) {
            if(S[i-1] == S[i])
                ++same;
            else{
                ans += same * (same + 1) / 2;
                same = 1;
            }
        }
        return ans;
    }
};