//Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/ 
class Solution {
public:
    int f(string &str) {
        map<int, int> m;
        int mx = INT_MAX;
        
        for(char c : str)
            ++m[c];
        //for(auto it : m) 
        //    mx = min(mx, it.second);
        return m.begin()->second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q, w;
        for(auto &query: queries) {
            q.push_back(f(query));
        }
        for(auto &word : words)
            w.push_back(f(word));
        sort(w.begin(), w.end());
        vector<int> ans;
        for(auto cnt : q) {
            ans.push_back(w.end() - upper_bound(w.begin(), w.end(), cnt));
        }
        return ans;
    }
};