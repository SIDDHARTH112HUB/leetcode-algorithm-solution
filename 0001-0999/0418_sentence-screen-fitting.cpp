//Link: https://leetcode.com/problems/sentence-screen-fitting/ 
class Solution {
public:
    int wordsTyping(vector<string>& s, int rows, int cols) {
        int n = s.size();
        vector<int> next(n, -1), times(n);
        int i = 0, ans = 0;
        while(rows > 0) {
            if(next[i] == -1) {
                int t = i, pos = 0, time = 0;
                while(pos + s[t].size() <= cols) {
                    pos += s[t].size() + 1;
                    ++t;
                    if(t == s.size()) {
                        t = 0;
                        ++time;
                    }
                }
                next[i] = t;
                times[i] = time;
                i = t;
                ans += time;
            }else {
                ans += times[i];
                i = next[i];
            }
            --rows;
        }
        return ans;
    }
};