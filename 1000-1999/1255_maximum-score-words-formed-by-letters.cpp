//Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/ 
class Solution {
public:
    unordered_map<int, int> cnt;
    int ans = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto c : letters) 
            ++cnt[c];
        dfs(words, score, 0, 0);
        return ans;
    }
    
    void dfs(vector<string>& words, vector<int>& score, int idx, int s) {
        if(idx >= words.size()) {
            ans = max(ans, s);
            return;
        }
        auto &word = words[idx];
        dfs(words,score, idx + 1, s);
        unordered_map<int, int> tmp;
        for(auto c : word)
            ++tmp[c];
        for(auto &it : tmp) {
            if(it.second > cnt[it.first])
                return;
        }
        for(auto &it : tmp) {
            cnt[it.first] -= it.second;
            s += score[it.first - 'a'] * it.second;
        }
        dfs(words, score, idx + 1, s);
        for(auto &it : tmp) {
            cnt[it.first] += it.second;
        }
    }
};