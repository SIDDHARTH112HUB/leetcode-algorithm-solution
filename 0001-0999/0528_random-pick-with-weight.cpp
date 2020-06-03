//Link: https://leetcode.com/problems/random-pick-with-weight/ 
class Solution {
public:
    vector<int> ww;
    Solution(vector<int>& w) {
        for(int i = 1; i < w.size(); ++i) {
            w[i] += w[i-1];
        }
        ww = w;
    }
    
    int pickIndex() {
        int n = rand() % ww.back();
        return upper_bound(ww.begin(), ww.end(), n) - ww.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */