[352.data-stream-as-disjoint-intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)  

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

\[1, 1\]
\[1, 1\], \[3, 3\]
\[1, 1\], \[3, 3\], \[7, 7\]
\[1, 3\], \[7, 7\]
\[1, 3\], \[6, 7\]

**Follow up:**

What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?  



**Solution:**  

```cpp
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
```
      