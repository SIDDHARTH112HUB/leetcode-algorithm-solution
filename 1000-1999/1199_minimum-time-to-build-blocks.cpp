//Link: https://leetcode.com/problems/minimum-time-to-build-blocks/ 
class Solution {
public:
    unordered_map<int, map<int, int> > m;
    int minBuildTime(vector<int>& blocks, int split) {
        sort(blocks.begin(), blocks.end());
        reverse(blocks.begin(), blocks.end());
        return h(blocks, 0, split, 1);
    }
    
    int h(vector<int>& blocks, int idx, int split, int worker) {
        if(blocks.size() - idx <= worker) {
            return blocks[idx];
        }
        int res = INT_MAX;
        auto it = m[idx].upper_bound(worker);
        if(it != m[idx].begin()){
            --it;
            return it->second;
        }
        for(int i = worker - 1; i >= 0; --i) {
            res = min(res, h(blocks, idx + i, split, (worker - i) * 2 ) + split);
            if(i > 0)
                res = max(res == INT_MAX ? 0 : res, blocks[idx]);
        }
        m[idx][worker] = res;
        return res;
    }
};
