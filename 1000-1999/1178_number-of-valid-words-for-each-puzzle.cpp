//Link: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/ 
typedef long long ll;
class Solution {
public:
    unordered_map<int, int> wordMap;
    void f(vector<string> &words, unordered_map<int, int>  &m) {
        for(int i = 0; i < words.size(); ++i) {
            auto &word = words[i];
            int mask = 0;
            for(auto c : word)
                mask |= 1 << (c-'a');
            ++m[mask];
        }
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        f(words, wordMap);
        vector<int> ans(puzzles.size());
        for(int i = 0; i < puzzles.size(); ++i) {
            auto &str = puzzles[i];
            for(int j = 0; j < (1 << (str.size() - 1)); ++j) {
                int mask = (1 << (str[0] - 'a'));
                for(int k = 1; k < str.size(); ++k) {
                    if( (j >> (k-1) ) & 1)
                        mask |= (1 << (str[k] - 'a'));
                }
                ans[i] += wordMap[mask];
            }
        }
        return ans;
    }
};