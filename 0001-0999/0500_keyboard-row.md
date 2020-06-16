[500.keyboard-row](https://leetcode.com/problems/keyboard-row/)  

Given a List of words, return the words that can be typed using letters of **alphabet** on only one row's of American keyboard like the image below.

![](https://assets.leetcode.com/uploads/2018/10/12/keyboard.png)

 

**Example:**

  
**Input:** \["Hello", "Alaska", "Dad", "Peace"\]
  
**Output:** \["Alaska", "Dad"\]
  

**Note:**

1.  You may use one character in the keyboard more than once.
2.  You may assume the input string will only contain letters of alphabet.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> m = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        map<int, int> cm;
        for(int i = 0; i < 3; ++i) {
            for(auto c : m[i])
                cm[c] = i;
        }
        vector<string> ans;
        for(auto &w : words) {
            set<int> t;
            for(char c : w) {
                t.insert(cm[c]);
            }
            if(t.size() == 1)
                ans.push_back(w);
        }
        return ans;
    }
};
```
      