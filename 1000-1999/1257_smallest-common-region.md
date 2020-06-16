[1257.smallest-common-region](https://leetcode.com/problems/smallest-common-region/)  

You are given some lists of `regions` where the first region of each list includes all other regions in that list.

Naturally, if a region `X` contains another region `Y` then `X` is bigger than `Y`. Also by definition a region X contains itself.

Given two regions `region1`, `region2`, find out the **smallest** region that contains both of them.

If you are given regions `r1`, `r2` and `r3` such that `r1` includes `r3`, it is guaranteed there is no `r2` such that `r2` includes `r3`.  
  
It's guaranteed the smallest region exists.

**Example 1:**

  
**Input:** regions = \[\["Earth","North America","South America"\],  
\["North America","United States","Canada"\],  
\["United States","New York","Boston"\],  
\["Canada","Ontario","Quebec"\],  
\["South America","Brazil"\]\],  
region1 = "Quebec",  
region2 = "New York"  
**Output:** "North America"  

**Constraints:**

*   `2 <= regions.length <= 10^4`
*   `region1 != region2`
*   All strings consist of English letters and spaces with at most 20 letters.  



**Solution:**  

```cpp
class Solution {
public:
    map<string, unordered_set<string> > g;
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        for(auto &rs : regions) {
            for(int i = 1; i < rs.size(); ++i)
                g[rs[0]].insert(rs[i]);
            //cout<<rs[0]<<endl;
        }
        vector<string> arr;
        for(auto &it : g) {
            //cout<<it.first<<endl;
            auto r = h(it.first, region1, region2);
            if(r.second == 2)
                return r.first;
        }
        //if(arr.size() == 1) return arr[0];
        return "";
    }
    
    pair<string, int> h(string cur, string &region1, string &region2) {
        vector<string> arr;
        if(cur == region1 || cur == region2) arr.push_back(cur);
        for(auto &n : g[cur]) {
            auto res = h(n, region1, region2);
            if(res.second == 2) return res;
            if(res.first.size() > 0)
                arr.push_back(res.first);
        }
        if(arr.size() >= 2) return {cur, 2};
        if(arr.size() == 1) return {arr[0], 1};
        return {"", 0};
    }
};
```
      