//Link: https://leetcode.com/problems/single-row-keyboard/ 
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<int, int> m;
        for(int i = 0; i < keyboard.size(); ++i ){
            m[keyboard[i]] = i;
        }
        int prev = 0, ans = 0;
        for(char c : word) {
            if(m[c] != prev) {
                ans += abs(m[c] - prev);
                prev = m[c];
            }
        }
        return ans;
    }
};