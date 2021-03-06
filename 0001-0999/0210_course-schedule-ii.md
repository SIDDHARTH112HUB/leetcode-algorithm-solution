[210.course-schedule-ii](https://leetcode.com/problems/course-schedule-ii/)  

There are a total of _n_ courses you have to take, labeled from `0` to `n-1`.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: `[0,1]`

Given the total number of courses and a list of prerequisite **pairs**, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

**Example 1:**

  
**Input:** 2, \[\[1,0\]\] 
  
**Output:** `[0,1]`
  
**Explanation:** There are a total of 2 courses to take. To take course 1 you should have finished   
  
             course 0. So the correct course order is `[0,1] .`

**Example 2:**

  
**Input:** 4, \[\[1,0\],\[2,0\],\[3,1\],\[3,2\]\]
  
**Output:** `[0,1,2,3] or [0,2,1,3]`
  
**Explanation:** There are a total of 4 courses to take. To take course 3 you should have finished both     
  
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
  
             So one correct course order is `[0,1,2,3]`. Another correct ordering is `[0,2,1,3] .`

**Note:**

1.  The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about [how a graph is represented](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs).
2.  You may assume that there are no duplicate edges in the input prerequisites.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, unordered_set<int> > course;
        for( auto &p:prerequisites){
            course[p.first].insert(p.second);
        }
        for( int i = 0; i<numCourses; i++)
            if( !dfs(course, i) )
                return {};
        return ans;
    }
    unordered_set<int> visited;
    unordered_set<int> visiting;
    bool dfs(map<int, unordered_set<int> > &courses, int cur ){
        if( visited.find(cur) != visited.end() )
            return true;
        visiting.insert(cur);
        for(auto &pre_course:courses[cur]){
            if( visiting.find(pre_course) != visiting.end() || !dfs(courses, pre_course))
                return false;
        }
        visiting.erase(cur);
        visited.insert(cur);
        ans.push_back(cur);
        return true;
    }
};
```
      