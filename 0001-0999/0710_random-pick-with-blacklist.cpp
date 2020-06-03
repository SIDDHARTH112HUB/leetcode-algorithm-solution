//Link: https://leetcode.com/problems/random-pick-with-blacklist/ 
class Solution {
public:
    vector<pair<int, int> > interval;
    int n = 0;
    Solution(int N, vector<int> blacklist) {
        int size = blacklist.size();
        n = N;
        if( size == 0 ) return;
        size += 1;
        blacklist.push_back(N);
        sort(blacklist.begin(), blacklist.end());
        
        if(blacklist[0] > 0) interval.push_back({ 0,  blacklist[0]});
        for( int i = 1; i<size; i++ ){
            if(blacklist[i] > blacklist[i-1] + 1) {
                interval.push_back({blacklist[i-1]+1, blacklist[i]});
            }
        }
    }
    
    int pick() {
        if(interval.size() == 0)
            return rand() % n;
        int r = rand();
        int idx = r % interval.size();
        return r % (interval[idx].second - interval[idx].first) + interval[idx].first;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */