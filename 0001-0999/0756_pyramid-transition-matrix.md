[756.pyramid-transition-matrix](https://leetcode.com/problems/pyramid-transition-matrix/)  

We are stacking blocks to form a pyramid. Each block has a color which is a one letter string.

We are allowed to place any color block `C` on top of two adjacent blocks of colors `A` and `B`, if and only if `ABC` is an allowed triple.

We start with a bottom row of `bottom`, represented as a single string. We also start with a list of allowed triples `allowed`. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

**Example 1:**

  
**Input:** bottom = "BCD", allowed = \["BCG", "CDE", "GEA", "FFF"\]  
**Output:** true  
**Explanation:**  
We can stack the pyramid like this:  
    A  
   / \\  
  G   E  
 / \\ / \\  
B   C   D  
  
We are allowed to place G on top of B and C because BCG is an allowed triple.  Similarly, we can place E on top of C and D, then A on top of G and E.

**Example 2:**

  
**Input:** bottom = "AABA", allowed = \["AAA", "AAB", "ABA", "ABB", "BAC"\]  
**Output:** false  
**Explanation:**  
We can't stack the pyramid to the top.  
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.  

**Constraints:**

*   `bottom` will be a string with length in range `[2, 8]`.
*   `allowed` will have length in range `[0, 200]`.
*   Letters in all strings will be chosen from the set `{'A', 'B', 'C', 'D', 'E', 'F', 'G'}`.  



**Solution:**  

```cpp
class Solution {
public:
    map<string, set<char> > dict;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if( bottom.size() <= 1 )
            return true;
        if( dict.size() == 0 ){
            for( auto &str : allowed){
                dict[str.substr(0,2)].insert(str[2]);
            }
        }
        return dfs(bottom, "");
    }
    
    bool dfs(string bottom, string above ){
        if( above.size() == 1 && bottom.size() == 2 ) return true;
        if( above.size() + 1 == bottom.size() ) return dfs(above, "");
        int idx = above.size();
        string s = {bottom[idx], bottom[idx+1]};
        for( auto c : dict[s]){
            bool res = dfs( bottom, above+c);
            if( res )
                return res;
        }
        return false;
    }
};
```
      