//Link: https://leetcode.com/problems/sentence-similarity-ii/ 

class Solution {
public:
    unordered_map<string, string> m;
    string find(string &s) {
        if(m.count(s) == 0 || m[s] == s) return m[s] = s;
        return m[s] = find(m[s]);
    }
    void combine(string &a, string &b) {
        
        m[find(a)] = m[find(b)];
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size()  ) return false;
        for(auto &p : pairs) {
            combine(p[0], p[1]);
        }
        for(int i = 0; i < words1.size(); ++i) {
            if(find(words1[i]) != find(words2[i]))
                return false;
        }
        return true;
    }
};