[293.flip-game](https://leetcode.com/problems/flip-game/)  

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: `+` and `-`, you and your friend take turns to flip two **consecutive** `"++"` into `"--"`. The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

**Example:**

  
**Input:** `s = "++++"`
  
**Output:** 
  
\[
  
  "--++",
  
  "+--+",
  
  "++--"
  
\]
  

**Note:** If there is no valid move, return an empty list `[]`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == '+' && s[i-1] == '+') {
                s[i] = '-'; s[i-1] = '-';
                ans.push_back(s);
                s[i] = '+'; s[i-1] = '+';
            }
        }
        return ans;
    }
};
```
      