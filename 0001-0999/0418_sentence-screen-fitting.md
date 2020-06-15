[418.sentence-screen-fitting](https://leetcode.com/problems/sentence-screen-fitting/)  

Given a `rows x cols` screen and a sentence represented by a list of **non-empty** words, find **how many times** the given sentence can be fitted on the screen.

**Note:**

1.  A word cannot be split into two lines.
2.  The order of words in the sentence must remain unchanged.
3.  Two consecutive words **in a line** must be separated by a single space.
4.  Total words in the sentence won't exceed 100.
5.  Length of each word is greater than 0 and won't exceed 10.
6.  1 ≤ rows, cols ≤ 20,000.

**Example 1:**

**Input:**
rows = 2, cols = 8, sentence = \["hello", "world"\]

**Output:** 
1

**Explanation:**
hello---
world---

The character '-' signifies an empty space on the screen.

**Example 2:**

**Input:**
rows = 3, cols = 6, sentence = \["a", "bcd", "e"\]

**Output:** 
2

**Explanation:**
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.

**Example 3:**

**Input:**
rows = 4, cols = 5, sentence = \["I", "had", "apple", "pie"\]

**Output:** 
1

**Explanation:**
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.  



**Solution:**  

```cpp
class Solution {
public:
    int wordsTyping(vector<string>& s, int rows, int cols) {
        int n = s.size();
        vector<int> next(n, -1), times(n);
        int i = 0, ans = 0;
        while(rows > 0) {
            if(next[i] == -1) {
                int t = i, pos = 0, time = 0;
                while(pos + s[t].size() <= cols) {
                    pos += s[t].size() + 1;
                    ++t;
                    if(t == s.size()) {
                        t = 0;
                        ++time;
                    }
                }
                next[i] = t;
                times[i] = time;
                i = t;
                ans += time;
            }else {
                ans += times[i];
                i = next[i];
            }
            --rows;
        }
        return ans;
    }
};
```
      