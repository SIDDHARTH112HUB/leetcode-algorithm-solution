//Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/ 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int, int> m;
        for(auto c : p)
            ++m[c];
        vector<int> ans;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(--m[c] == 0)
                m.erase(c);
            if(i >= p.size()) {
                char c2 = s[i-p.size()];
                if(++m[c2] == 0)
                    m.erase(c2);
            }
            if(m.size() == 0)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};