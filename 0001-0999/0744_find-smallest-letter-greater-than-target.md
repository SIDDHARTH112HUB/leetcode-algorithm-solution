[744.find-smallest-letter-greater-than-target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)  

Given a list of sorted characters `letters` containing only lowercase letters, and given a target letter `target`, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is `target = 'z'` and `letters = ['a', 'b']`, the answer is `'a'`.

**Examples:**  

**Input:**
letters = \["c", "f", "j"\]
target = "a"
**Output:** "c"

**Input:**
letters = \["c", "f", "j"\]
target = "c"
**Output:** "f"

**Input:**
letters = \["c", "f", "j"\]
target = "d"
**Output:** "f"

**Input:**
letters = \["c", "f", "j"\]
target = "g"
**Output:** "j"

**Input:**
letters = \["c", "f", "j"\]
target = "j"
**Output:** "c"

**Input:**
letters = \["c", "f", "j"\]
target = "k"
**Output:** "c"

**Note:**  

1.  `letters` has a length in range `[2, 10000]`.
2.  `letters` consists of lowercase letters, and contains at least 2 unique letters.
3.  `target` is a lowercase letter.  



**Solution:**  

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for( auto c:  letters ){
            if( c> target)
                return c;
        }
        return letters[0];
    }
};
```
      