[1203.sort-items-by-groups-respecting-dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)  

There are `n` items each belonging to zero or one of `m` groups where `group[i]` is the group that the `i`\-th item belongs to and it's equal to `-1` if the `i`\-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

*   The items that belong to the same group are next to each other in the sorted list.
*   There are some relations between these items where `beforeItems[i]` is a list containing all the items that should come before the `i`\-th item in the sorted array (to the left of the `i`\-th item).

Return any solution if there is more than one solution and return an **empty list** if there is no solution.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/09/11/1359_ex1.png)**

**Input:** n = 8, m = 2, group = \[-1,-1,1,0,0,1,0,-1\], beforeItems = \[\[\],\[6\],\[5\],\[6\],\[3,6\],\[\],\[\],\[\]\]
**Output:** \[6,3,4,1,5,2,0,7\]

**Example 2:**

**Input:** n = 8, m = 2, group = \[-1,-1,1,0,0,1,0,-1\], beforeItems = \[\[\],\[6\],\[5\],\[6\],\[3\],\[\],\[4\],\[\]\]
**Output:** \[\]
**Explanation:** This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

**Constraints:**

*   `1 <= m <= n <= 3*10^4`
*   `group.length == beforeItems.length == n`
*   `-1 <= group[i] <= m-1`
*   `0 <= beforeItems[i].length <= n-1`
*   `0 <= beforeItems[i][j] <= n-1`
*   `i != beforeItems[i][j]`
*   `beforeItems[i]` does not contain duplicates elements.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, int> groupInDegree, itemInDegree;
        unordered_map<int, set<int> > groupGraph, itemGroup;
        int maxGroup = m;
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) {
                group[i] = maxGroup++;
            }
        }
        for(int i = 0; i < beforeItems.size(); ++i) {
            auto &items = beforeItems[i];
            auto g = group[i];
            for(auto item: items){
                if(g != group[item] && groupGraph[g].count(group[item]) == 0){
                    ++groupInDegree[group[item]];
                
                    groupGraph[g].insert(group[item]);
                }
                ++itemInDegree[item];
                itemGroup[i].insert(item);
            }
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < maxGroup; ++i) {
            if(groupInDegree[i] == 0){
                //cout<<"groupInDegree:"<<i<<" "<<groupInDegree[i]<<endl;
                q.push(i);
            }
        }
        vector<int> groupOrder;
        while(q.size()) {
            int g = q.front();
            q.pop();
            ++cnt;
            groupOrder.push_back(g);
            for(auto next : groupGraph[g]) {
                if(--groupInDegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if(cnt != maxGroup) {
            //cout<<"no max group "<<cnt<<" "<<groupOrder.size()<<endl;
            return {};
        }
        q = {};
        for(int i = 0; i < n; ++i) {
            if(itemInDegree[i] == 0)
                q.push(i);
        }
        vector<vector<int>> grouparr(maxGroup);
        while(q.size()) {
            int item = q.front();
            q.pop();
            grouparr[group[item]].push_back(item);
            for(auto next : itemGroup[item]) {
                if(--itemInDegree[next] == 0)
                    q.push(next);
            }
        }
        vector<int> ans;
        for(auto g : groupOrder)
            for(auto n : grouparr[g])
                ans.push_back(n);
        if(ans.size() != n) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      