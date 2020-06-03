//Link: https://leetcode.com/problems/count-the-repetitions/ 
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();
        int cnt = 0, j = 0;
        vector<int> repeatCnt(n1 + 1);
        vector<int> next(n1 + 1);
        for(int k = 1; k <= n1; ++k) {
            for(int i = 0; i < l1; ++i){
                if(s1[i] == s2[j]){
                    ++j;
                }
                if(j == l2){
                    j = 0;
                    ++cnt;
                }
            }
            repeatCnt[k] = cnt;
            next[k] = j;
            for(int b = 0; b < k; ++b) {
                if(next[b] == j){
                    int interval = (k - b);
                    int repeat = (n1 - b) / interval;
                    int patternCnt = (repeatCnt[k] - repeatCnt[b]) * repeat;
                    int remainCnt = repeatCnt[b + (n1 - b) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return cnt / n2;
    }
};