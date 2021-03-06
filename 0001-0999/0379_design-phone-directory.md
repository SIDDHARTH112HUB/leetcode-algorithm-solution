[379.design-phone-directory](https://leetcode.com/problems/design-phone-directory/)  

Design a Phone Directory which supports the following operations:

1.  `get`: Provide a number which is not assigned to anyone.
2.  `check`: Check if a number is available or not.
3.  `release`: Recycle or release a number.

**Example:**

  
// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.  
PhoneDirectory directory = new PhoneDirectory(3);  
  
// It can return any available phone number. Here we assume it returns 0.  
directory.get();  
  
// Assume it returns 1.  
directory.get();  
  
// The number 2 is available, so return true.  
directory.check(2);  
  
// It returns 2, the only number that is left.  
directory.get();  
  
// The number 2 is no longer available, so return false.  
directory.check(2);  
  
// Release number 2 back to the pool.  
directory.release(2);  
  
// Number 2 is available again, return true.  
directory.check(2);  

**Constraints:**

*   `1 <= maxNumbers <= 10^4`
*   `0 <= number < maxNumbers`
*   The total number of call of the methods is between `[0 - 20000]`  



**Solution:**  

```cpp
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    
    int mx;
    set<int> v;
    list<int> l;
    int start = 0;
    PhoneDirectory(int maxNumbers) {
        mx = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(l.size() == 0) {
            if(start == mx) return -1;
            v.insert(start);
            return start++;
        }
        auto it = l.begin();
        int res = *it;
        v.insert(res);
        l.erase(it);
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return v.count(number) == 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(v.count(number)) {
            v.erase(number);
            l.push_back(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```
      