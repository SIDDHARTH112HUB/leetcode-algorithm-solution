[547.friend-circles](https://leetcode.com/problems/friend-circles/)  

There are **N** students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a **direct** friend of B, and B is a **direct** friend of C, then A is an **indirect** friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a **N\*N** matrix **M** representing the friend relationship between students in the class. If M\[i\]\[j\] = 1, then the ith and jth students are **direct** friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

**Example 1:**  

  
**Input:** 
  
\[\[1,1,0\],
  
 \[1,1,0\],
  
 \[0,0,1\]\]
  
**Output:** 2
  
**Explanation:**The 0th and 1st students are direct friends, so they are in a friend circle.   
The 2nd student himself is in a friend circle. So return 2.
  

**Example 2:**  

  
**Input:** 
  
\[\[1,1,0\],
  
 \[1,1,1\],
  
 \[0,1,1\]\]
  
**Output:** 1
  
**Explanation:**The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,   
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
  

**Note:**  

1.  N is in range \[1,200\].
2.  M\[i\]\[i\] = 1 for all students.
3.  If M\[i\]\[j\] = 1, then M\[j\]\[i\] = 1.  



**Solution:**  

```cpp
struct UF {
    unordered_map<int, int> m;
    int group = 0;
    int find(int x) {
        if(m.count(x)) {
            if(m[x] == x)
                return x;
            return m[x] = find(m[x]);
        }
        m[x] = x;
        ++group;
        return x;
    }
    
    bool combine(int a, int b) {
        a = find(a);
        b = find(b);
        if( a != b) {
            --group;
            m[b] = a;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF uf;
        for(int i = 0; i < M.size(); ++i) {
            for(int j = i; j < M[i].size(); ++j) {
                if(M[i][j] == 1)
                    uf.combine(i, j);
            }
        }
        return uf.group;
    }
};
```
      