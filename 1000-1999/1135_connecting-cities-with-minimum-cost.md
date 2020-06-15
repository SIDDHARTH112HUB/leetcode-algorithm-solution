[1135.connecting-cities-with-minimum-cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)  

There are `N` cities numbered from 1 to `N`.

You are given `connections`, where each `connections[i] = [city1, city2, cost]` represents the cost to connect `city1` and `city2` together.  (A _connection_ is bidirectional: connecting `city1` and `city2` is the same as connecting `city2` and `city1`.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/04/20/1314_ex2.png)

**Input:** N = 3, connections = \[\[1,2,5\],\[1,3,6\],\[2,3,1\]\]
**Output:** 6
**Explanation:** 
Choosing any 2 edges will connect all cities so we choose the minimum 2.

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/04/20/1314_ex1.png)

**Input:** N = 4, connections = \[\[1,2,3\],\[3,4,4\]\]
**Output:** \-1
**Explanation:** 
There is no way to connect all cities even if all edges are used.

**Note:**

1.  `1 <= N <= 10000`
2.  `1 <= connections.length <= 10000`
3.  `1 <= connections[i][0], connections[i][1] <= N`
4.  `0 <= connections[i][2] <= 10^5`
5.  `connections[i][0] != connections[i][1]`  



**Solution:**  

```cpp

struct UF {
    
    unordered_map<int, int> m;
    int group = 0;
    int find(int p) {
        if(m.count(p)) {
            if(m[p] == p)
                return p;
            m[p] = find(m[p]);
            return m[p];
        }
        m[p] = p;
        ++group;
        return p;
    }
    
    bool combine(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b) {
            m[b] = a;
            --group;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& conections) {
        //map<int, pair<int, int> > c;
        unordered_set<int> v;
        sort(conections.begin(), conections.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        int ans = 0;
        UF uf;
        for(auto &con: conections){
            int a = con[0], b = con[1];
            if(a==b) continue;
            //if(v.count(a) && v.count(b))
            //    continue;
            if(uf.combine(a, b))
                ans += con[2];
            v.insert(a);
            v.insert(b);
        }
        return v.size() == N && uf.group == 1? ans:-1;
    }
};
```
      