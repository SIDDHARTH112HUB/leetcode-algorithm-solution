[1286.iterator-for-combination](https://leetcode.com/problems/iterator-for-combination/)  

Design an Iterator class, which has:

*   A constructor that takes a string `characters` of **sorted distinct** lowercase English letters and a number `combinationLength` as arguments.
*   A function _next()_ that returns the next combination of length `combinationLength` in **lexicographical order**.
*   A function _hasNext()_ that returns `True` if and only if there exists a next combination.

**Example:**

  
CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.  
  
iterator.next(); // returns "ab"  
iterator.hasNext(); // returns true  
iterator.next(); // returns "ac"  
iterator.hasNext(); // returns true  
iterator.next(); // returns "bc"  
iterator.hasNext(); // returns false  

**Constraints:**

*   `1 <= combinationLength <= characters.length <= 15`
*   There will be at most `10^4` function calls per test.
*   It's guaranteed that all calls of the function `next` are valid.  



**Solution:**  

```cpp
class CombinationIterator {
public:
    string str;
    vector<int> pos;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        pos.resize(combinationLength);
        for(int i = 0; i < pos.size(); ++i)
            pos[i] = i;
    }
    
    int helper(int i) {
        if(i == -1) return str.size();
        if(pos[i] + (pos.size() - i) >= str.size() ) 
            return pos[i] = helper(i-1) + 1;
        else
            return pos[i] += 1;
    }
    string next() {
        string s;
        for(auto p : pos)
            s += str[p];
        helper(pos.size()-1);
        return s;
    }
    
    bool hasNext() {
        return pos[0] < str.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
      