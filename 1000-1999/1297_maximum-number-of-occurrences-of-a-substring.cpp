//Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ 
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //int ans = 0;
        //map<int, int> m;
        map<string, int> ms;
        int b = 0, e = 0;
        for(int i = 0; i <= s.size() - minSize; ++i) {
            map<int, int> m;
            for(int k = 0; k < minSize; ++k) {
                ++m[s[k+i]];
            }
            if(m.size() > maxLetters) continue;
            ++ms[s.substr(i, minSize)];
        }
        string ans;
        int mx = 0;
        for(auto it : ms) {
            mx = max(mx, it.second);
        }
        return mx;
    }
};