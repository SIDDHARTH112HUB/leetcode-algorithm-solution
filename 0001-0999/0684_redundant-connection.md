[684.redundant-connection](https://leetcode.com/problems/redundant-connection/)  

In this problem, a tree is an **undirected** graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of `edges`. Each element of `edges` is a pair `[u, v]` with `u < v`, that represents an **undirected** edge connecting nodes `u` and `v`.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge `[u, v]` should be in the same format, with `u < v`.

**Example 1:**  

  
**Input:** \[\[1,2\], \[1,3\], \[2,3\]\]
  
**Output:** \[2,3\]
  
**Explanation:** The given undirected graph will be like this:
  
  1
  
 / \\
  
2 - 3
  

**Example 2:**  

  
**Input:** \[\[1,2\], \[2,3\], \[3,4\], \[1,4\], \[1,5\]\]
  
**Output:** \[1,4\]
  
**Explanation:** The given undirected graph will be like this:
  
5 - 1 - 2
  
    |   |
  
    4 - 3
  

**Note:**  

*   The size of the input 2D-array will be between 3 and 1000.
*   Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

  

**Update (2017-09-26):**  
We have overhauled the problem description + test cases and specified clearly the graph is an **_undirected_** graph. For the **_directed_** graph follow up please see **[Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/description/)**). We apologize for any inconvenience caused.  



**Solution:**  

```cpp
//Template<class T, class CT>
class UnionSet{
    int cnt = 0;
    map<int, int> parent;
public:
    int find( int x ){
        if(x != parent[x])
            return find(parent[x]);
        return x;
    }
    int add(int x){
        if( !parent[x] ){
            parent[x] = x;
            cnt++;
            return x;
        }else{
            return find(x);
        }
    }
    bool combine(int i, int j){
        int x1 = find(i);
        int x2 = find(j);
        if( !x1 )
            x1 = add(i);
        if( !x2 )
            x2 = add(j);
        if( x1 != x2 ){
            parent[x1] = x2;
            cnt--;
            return true;
        }else
            return false;
    }
    int count(){
        return cnt;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet us;
        for(auto &e:edges){
            bool res = us.combine(e[0], e[1]);
            if( !res )
                return e;
        }
        return {0,0};
    }
};
```
      