//Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals/ 
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    SummaryRanges() {
    }
    
    void addNum(int val) {
        if(m.count(val)) return;
        m[val] = val;
        int mn = val, mx = val;
        if (m.count(val - 1)) mn = m[val-1];
        if (m.count(val + 1)) mx = m[val + 1];
        m[mn] = mx;
        m[mx] = mn;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int> > ans;
        auto it = m.begin();
        while(it != m.end()) {
            ans.push_back({it->first, it->second});
            if(it->first == it->second)
                ++it;
            else
                it = m.upper_bound(it->second);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */