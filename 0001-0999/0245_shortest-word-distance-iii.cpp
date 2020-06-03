//Link: https://leetcode.com/problems/shortest-word-distance-iii/ 
class Solution {
public:
    map<string, vector<int> > m;
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for(int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
        int i = 0, j = 0;
        int ans = INT_MAX;
        auto &v1 = m[word1], &v2 = m[word2];
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] == v2[j]) {
                ++i;continue;
            }
            ans = min(ans, abs(v1[i] - v2[j]));
            if(v1[i] > v2[j]) ++j;
            else if(v1[i] < v2[j]) ++i;
        }
        return ans;
    }
};