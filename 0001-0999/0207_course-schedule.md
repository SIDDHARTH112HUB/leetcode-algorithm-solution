[207.course-schedule](https://leetcode.com/problems/course-schedule/)  

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses-1`.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: `[0,1]`

Given the total number of courses and a list of prerequisite **pairs**, is it possible for you to finish all courses?

**Example 1:**

  
**Input:** numCourses = 2, prerequisites = \[\[1,0\]\]  
**Output:** true  
**Explanation:** There are a total of 2 courses to take.   
             To take course 1 you should have finished course 0. So it is possible.  

**Example 2:**

  
**Input:** numCourses = 2, prerequisites = \[\[1,0\],\[0,1\]\]  
**Output:** false  
**Explanation:** There are a total of 2 courses to take.   
             To take course 1 you should have finished course 0, and to take course 0 you should  
             also have finished course 1. So it is impossible.  

**Constraints:**

*   The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about [how a graph is represented](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).
*   You may assume that there are no duplicate edges in the input prerequisites.
*   `1 <= numCourses <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    map<int, set<int> > g;
    map<int, int> d;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &p : prerequisites) {
            g[p[0]].insert(p[1]);
            ++d[p[0]];
        }
        for(int i = 0; i < numCourses; ++i) {
            set<int> v;
            if(!h(i, v))return false;
        }
        return true;
    }
    set<int> global_visit;
    bool h(int root, set<int> &v) {
        if(v.count(root)) return false;
        if(global_visit.count(root)) return true;
        v.insert(root);
        global_visit.insert(root);
        for(auto next : g[root]) {
            if(!h(next, v))return false;
        }
        v.erase(root);
        return true;
    }
};
```
      