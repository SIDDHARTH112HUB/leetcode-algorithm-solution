[251.flatten-2d-vector](https://leetcode.com/problems/flatten-2d-vector/)  

Design and implement an iterator to flatten a 2d vector. It should support the following operations: `next` and `hasNext`.

**Example:**

  
Vector2D iterator = new Vector2D(\[\[1,2\],\[3\],\[4\]\]);
  

  
iterator.next(); // return 1
  
iterator.next(); // return 2
  
iterator.next(); // return 3
  
iterator.hasNext(); // return true
  
iterator.hasNext(); // return true
  
iterator.next(); // return 4
  
iterator.hasNext(); // return false
  

**Notes:**

1.  Please remember to **RESET** your class variables declared in Vector2D, as static/class variables are **persisted across multiple test cases**. Please see [here](https://leetcode.com/faq/) for more details.
2.  You may assume that `next()` call will always be valid, that is, there will be at least a next element in the 2d vector when `next()` is called.

**Follow up:**

As an added challenge, try to code it using only [iterators in C++](http://www.cplusplus.com/reference/iterator/iterator/) or [iterators in Java](http://docs.oracle.com/javase/7/docs/api/java/util/Iterator.html).  



**Solution:**  

```cpp
class Vector2D {
public:
    int idx = 0;
    int idx2 = 0;
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
        while(idx < v.size() && v[idx].size() == 0) ++idx;
    }
    
    int next() {
        if(!hasNext()) return -1;
        int res = v[idx][idx2++];
        while(idx < v.size() && v[idx].size() <= idx2) {
            ++idx;
            idx2 = 0;
        }
        return res;
    }
    
    bool hasNext() {
        return v.size() > idx;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
      