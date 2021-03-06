[170.two-sum-iii-data-structure-design](https://leetcode.com/problems/two-sum-iii-data-structure-design/)  

Design and implement a TwoSum class. It should support the following operations: `add` and `find`.

`add` - Add the number to an internal data structure.  
`find` - Find if there exists any pair of numbers which sum is equal to the value.

**Example 1:**

  
add(1); add(3); add(5);
  
find(4) -> true
  
find(7) -> false
  

**Example 2:**

  
add(3); add(1); add(2);
  
find(3) -> true
  
find(6) -> false  



**Solution:**  

```cpp
class TwoSum {
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it : m) {
            int v = it.first;
            int v2 = value - v;
            if(v == v2) return it.second >= 2;
            if(m.count(v2)) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```
      