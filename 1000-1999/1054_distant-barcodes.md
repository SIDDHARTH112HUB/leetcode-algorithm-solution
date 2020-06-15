[1054.distant-barcodes](https://leetcode.com/problems/distant-barcodes/)  

In a warehouse, there is a row of barcodes, where the `i`\-th barcode is `barcodes[i]`.

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

**Example 1:**

**Input:** \[1,1,1,2,2,2\]
**Output:** \[2,1,2,1,2,1\]

**Example 2:**

**Input:** \[1,1,1,1,2,2,3,3\]
**Output:** \[1,3,1,3,2,1,2,1\]

**Note:**

1.  `1 <= barcodes.length <= 10000`
2.  `1 <= barcodes[i] <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for(int b : barcodes)
            ++m[b];
        priority_queue<pair<int, int> > pq;
        for(auto &it : m) 
            pq.push({it.second, it.first});
        vector<int> ans;
        pq.push({1, -1});
        while(pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans.push_back(a.second);
            if(b.second >= 0)
                ans.push_back(b.second);
            if(--a.first > 0)
                pq.push(a);
            if(--b.first > 0)
                pq.push(b);
        }
        return ans;
    }
};
```
      