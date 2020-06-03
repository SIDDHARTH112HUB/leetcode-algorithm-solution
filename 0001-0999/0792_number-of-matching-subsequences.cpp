//Link: https://leetcode.com/problems/number-of-matching-subsequences/ 
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int> > m;
        int ans = 0, i = 0;
        for( char c:S){
            m[c].push_back(i++);
        }
        for( auto &word: words){
            int cur = 0;
            int found = true;
            for(auto c : word) {
                auto &m2 = m[c];
                int idx = lower_bound(m2.begin(), m2.end(), cur) - m2.begin();
                if(idx >= m2.size()) {
                    found = false;
                    break;
                }
                cur = m2[idx] + 1;
            }
            if(found)
                ++ans;
        }
        return ans;
    }
};