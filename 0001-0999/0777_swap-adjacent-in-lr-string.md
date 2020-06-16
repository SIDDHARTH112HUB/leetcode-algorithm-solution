[777.swap-adjacent-in-lr-string](https://leetcode.com/problems/swap-adjacent-in-lr-string/)  

In a string composed of `'L'`, `'R'`, and `'X'` characters, like `"RXXLRXRXL"`, a move consists of either replacing one occurrence of `"XL"` with `"LX"`, or replacing one occurrence of `"RX"` with `"XR"`. Given the starting string `start` and the ending string `end`, return `True` if and only if there exists a sequence of moves to transform one string to the other.

**Example:**

  
**Input:** start = "RXXLRXRXL", end = "XRLXXRRLX"  
**Output:** True  
**Explanation:**  
We can transform start to end following these steps:  
RXXLRXRXL ->  
XRXLRXRXL ->  
XRLXRXRXL ->  
XRLXXRRXL ->  
XRLXXRRLX  

**Constraints:**

*   `1 <= len(start) == len(end) <= 10000`.
*   Both start and end will only consist of characters in `{'L', 'R', 'X'}`.  



**Solution:**  

```cpp
class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0, j=0;
        while(i<start.size() || j < end.size() ){
            while(i < start.size() && start[i] == 'X')i++;
            while(j < end.size() && end[j] == 'X')j++;
            if( i == start.size() || j == end.size() )
                return i == j;
            if( start[i] != end[j] ) return false;
            else if( start[i] == 'L' && j > i )return false;
            else if( start[i] == 'R' && i > j) return false;
            i++;j++;
        }
        return true;
    }
};
```
      