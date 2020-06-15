[281.zigzag-iterator](https://leetcode.com/problems/zigzag-iterator/)  

Given two 1d vectors, implement an iterator to return their elements alternately.

**Example:**

**Input:**
v1 = \[1,2\]
v2 = \[3,4,5,6\] 
**Output:** `[1,3,2,4,5,6]
**Explanation:**` By calling _next_ repeatedly until _hasNext_ returns `false`, the order of elements returned by _next_ should be: `[1,3,2,4,5,6]`.

**Follow up**:

What if you are given `k` 1d vectors? How well can your code be extended to such cases?

**Clarification** **for the follow up question****:**  
The "Zigzag" order is not clearly defined and is ambiguous for `k > 2` cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

**Input:**
\[1,2,3\]
\[4,5,6,7\]
\[8,9\]

**Output:** `[1,4,8,2,5,9,3,6,7]`.  



**Solution:**  

```cpp
class ZigzagIterator {
public:
    int i[2];
    int t = 0;
    vector<vector<int> > v;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.resize(2);
        i[0] = 0;i[1] = 0;
        v[0] = v1;
        v[1] = v2;
    }

    int next() {
        if(hasNext() == false) return -1;
        if(v[t].size() <= i[t]){
            ++t;
            t %= 2;
            return next();
        }
        int turn = t++;
        t %= 2;
        return v[turn][i[turn]++];
    }

    bool hasNext() {
        return i[0] < v[0].size() || i[1] < v[1].size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
```
      