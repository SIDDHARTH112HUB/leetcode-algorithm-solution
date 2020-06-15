[1136.parallel-courses](https://leetcode.com/problems/parallel-courses/)  

There are `N` courses, labelled from 1 to `N`.

We are given `relations[i] = [X, Y]`, representing a prerequisite relationship between course `X` and course `Y`: course `X` has to be studied before course `Y`.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return `-1`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/04/20/1316_ex1.png)**

**Input:** N = 3, relations = \[\[1,3\],\[2,3\]\]
**Output:** 2
**Explanation:** 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/04/20/1316_ex2.png)**

**Input:** N = 3, relations = \[\[1,2\],\[2,3\],\[3,1\]\]
**Output:** \-1
**Explanation:** 
No course can be studied because they depend on each other.

**Note:**

1.  `1 <= N <= 5000`
2.  `1 <= relations.length <= 5000`
3.  `relations[i][0] != relations[i][1]`
4.  There are no repeated relations in the input.  



**Solution:**  

```cpp
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, unordered_set<int> > m;
        unordered_map<int, unordered_set<int> > prev;
        for(auto &r : relations) {
            m[r[0]].insert(r[1]);
            prev[r[1]].insert(r[0]);
        }
        queue<int> q;
        unordered_set<int> v;
        int res = 0;
        for(int i = 1; i <= N; ++i){
            if(m[i].size() == 0){
                q.push(i);
                v.insert(i);
            }
        }
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                int c = q.front();
                q.pop();
                v.insert(c);
                for(auto n : prev[c]) {
                    m[n].erase(c);
                    if(m[n].size() == 0)
                        q.push(n);
                }
            }
            ++res;
        }
        return v.size()== N ? res: -1;
    }
};
```
      