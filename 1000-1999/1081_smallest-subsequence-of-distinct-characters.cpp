//Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ 
class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> cnt(256), v(256);
        for(char c : text)
            ++cnt[c];
        string ans;
        for(char c : text) {
            --cnt[c];
            if(v[c])
                continue;
            v[c] = 1;
            while(ans.size() && cnt[ans.back()] && c < ans.back()){
                v[ans.back()] = 0;
                ans.pop_back();
            }
            ans += c;
        }
        return ans;
    }
};