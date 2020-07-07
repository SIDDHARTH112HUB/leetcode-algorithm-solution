[1494.parallel-courses-ii](https://leetcode.com/problems/parallel-courses-ii/)  

Given the integer `n` representing the number of courses at some university labeled from `1` to `n`, and the array `dependencies` where `dependencies[i] = [xi, yi]`  represents a prerequisite relationship, that is, the course `xi` must be taken before the course `yi`.  Also, you are given the integer `k`.

In one semester you can take **at most** `k` courses as long as you have taken all the prerequisites for the courses you are taking.

_Return the minimum number of semesters to take all courses_. It is guaranteed that you can take all courses in some way.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_1.png)**

  
**Input:** n = 4, dependencies = \[\[2,1\],\[3,1\],\[1,4\]\], k = 2  
**Output:** 3   
**Explanation:** The figure above represents the given graph. In this case we can take courses 2 and 3 in the first semester, then take course 1 in the second semester and finally take course 4 in the third semester.  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/05/22/leetcode_parallel_courses_2.png)**

  
**Input:** n = 5, dependencies = \[\[2,1\],\[3,1\],\[4,1\],\[1,5\]\], k = 2  
**Output:** 4   
**Explanation:** The figure above represents the given graph. In this case one optimal way to take all courses is: take courses 2 and 3 in the first semester and take course 4 in the second semester, then take course 1 in the third semester and finally take course 5 in the fourth semester.  

**Example 3:**

  
**Input:** n = 11, dependencies = \[\], k = 2  
**Output:** 6  

**Constraints:**

*   `1 <= n <= 15`
*   `1 <= k <= n`
*   `0 <= dependencies.length <= n * (n-1) / 2`
*   `dependencies[i].length == 2`
*   `1 <= xi, yi <= n`
*   `xi != yi`
*   All prerequisite relationships are distinct, that is, `dependencies[i] != dependencies[j]`.
*   The given graph is a directed acyclic graph.  



**Solution:**  

```cpp
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int S = 1 << n;
        vector<int> dep(n);
        for(int i = 0; i < dependencies.size(); ++i) {
            dep[dependencies[i][1] - 1] |= 1 << (dependencies[i][0] - 1);
        }
        vector<int> dp(S);
        dp[0] = 1;
        for(int d = 1; d <= n; ++d) {
            vector<int> tmp(S);
            for(int s = 0; s < S; ++s) {
                int mask = 0;
                if(!dp[s]) continue;
                for(int i = 0; i < n; ++i) {
                    if(!(s & (1 << i) ) && ((dep[i] & s) == dep[i]) ) {
                        mask |= 1 << i;
                    }
                }
                
                if(__builtin_popcount(mask) <= k) {
                    tmp[s | mask] = 1;
                }else {
                    for(int c = mask; c; c = (c - 1) & mask) {
                        if(__builtin_popcount(c) <= k) {
                            tmp[s | c] = 1;
                        }
                    }
                }
            }
            if(tmp.back()) return d;
            dp.swap(tmp);
        }
        return -1;
    }
};
```
      