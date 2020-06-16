[604.design-compressed-string-iterator](https://leetcode.com/problems/design-compressed-string-iterator/)  

Design and implement a data structure for a compressed string iterator. It should support the following operations: `next` and `hasNext`.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

`next()` - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.  
`hasNext()` - Judge whether there is any letter needs to be uncompressed.

**Note:**  
Please remember to **RESET** your class variables declared in StringIterator, as static/class variables are **persisted across multiple test cases**. Please see [here](https://leetcode.com/faq/#different-output) for more details.

**Example:**

  
StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
  

  
iterator.next(); // return 'L'
  
iterator.next(); // return 'e'
  
iterator.next(); // return 'e'
  
iterator.next(); // return 't'
  
iterator.next(); // return 'C'
  
iterator.next(); // return 'o'
  
iterator.next(); // return 'd'
  
iterator.hasNext(); // return true
  
iterator.next(); // return 'e'
  
iterator.hasNext(); // return false
  
iterator.next(); // return ' '  



**Solution:**  

```cpp
class StringIterator {
public:
    string s;
    int idx = 0;
    int cnt = 0;
    char ch = 0;
    StringIterator(string compressedString) {
        s = compressedString;
    }
    
    char next() {
        if(!hasNext()) return ' ';
        if(cnt == 0) {
            ch = s[idx++];
            while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9')
                cnt = cnt * 10 + s[idx++] - '0';
        }
        --cnt;
        return ch;
    }
    
    bool hasNext() {
        if(cnt == 0 && idx >= s.size()) return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
      