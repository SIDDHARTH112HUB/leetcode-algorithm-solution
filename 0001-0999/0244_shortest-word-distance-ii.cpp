//Link: https://leetcode.com/problems/shortest-word-distance-ii/ 
class WordDistance {
public:
    map<string, vector<int> > m;
    WordDistance(vector<string>& words) {
        int i = 0;
        for(auto &w : words) {
            m[w].push_back(i++);
        }
    }
    
    int shortest(string w1, string w2) {
        auto &v2 = m[w2];
        int res = INT_MAX;
        for(auto idx : m[w1]) {
            //auto l = lower_bound(v2.begin(), v2.end(), idx);
            auto r = upper_bound(v2.begin(), v2.end(), idx);
            auto l = r;
            if(l != v2.begin()) --l;
            res = min(res, abs(*l - idx));
            if(r == v2.end()) --r;
            res = min(res, abs(*r - idx));
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */