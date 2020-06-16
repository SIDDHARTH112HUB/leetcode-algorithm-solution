[1079.letter-tile-possibilities](https://leetcode.com/problems/letter-tile-possibilities/)  

You have a set of `tiles`, where each tile has one letter `tiles[i]` printed on it.  Return the number of possible non-empty sequences of letters you can make.

**Example 1:**

  
**Input:** "AAB"
  
**Output:** 8
  
**Explanation:** The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
  

**Example 2:**

  
**Input:** "AAABBC"
  
**Output:** 188
  

**Note:**

1.  `1 <= tiles.length <= 7`
2.  `tiles` consists of uppercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_set<string> ans;
    int numTilePossibilities(string tiles) {
        string item;
        dfs(tiles, 0, item);
        return ans.size();
        
    }
    void dfs(string &tiles, int idx, string &item) {
        if(item.size() > tiles.size())
            return;
        //item.push_back(tiles)
        if(item.size() && ans.count(item) == 0)
            ans.insert(item);
        if(item.size() == tiles.size())
            return;
        for(int i = 0; i < tiles.size(); i++){
            if( tiles[i] == '.') continue;
            item.push_back(tiles[i]);
            char src = tiles[i];
            tiles[i] = '.';
            dfs(tiles, i+1, item);
            item.pop_back();
            tiles[i] = src;
        }
    }
};
```
      