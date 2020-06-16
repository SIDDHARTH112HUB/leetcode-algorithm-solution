[1307.verbal-arithmetic-puzzle](https://leetcode.com/problems/verbal-arithmetic-puzzle/)  

Given an equation, represented by `words` on left side and the `result` on right side.

You need to check if the equation is solvable under the following rules:

*   Each character is decoded as one digit (0 - 9).
*   Every pair of different characters they must map to different digits.
*   Each `words[i]` and `result` are decoded as one number **without** leading zeros.
*   Sum of numbers on left side (`words`) will equal to the number on right side (`result`). 

Return `True` if the equation is solvable otherwise return `False`.

**Example 1:**

  
**Input:** words = \["SEND","MORE"\], result = "MONEY"  
**Output:** true  
**Explanation:** Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'  
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652

**Example 2:**

  
**Input:** words = \["SIX","SEVEN","SEVEN"\], result = "TWENTY"  
**Output:** true  
**Explanation:** Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4  
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214

**Example 3:**

  
**Input:** words = \["THIS","IS","TOO"\], result = "FUNNY"  
**Output:** true  

**Example 4:**

  
**Input:** words = \["LEET","CODE"\], result = "POINT"  
**Output:** false  

**Constraints:**

*   `2 <= words.length <= 5`
*   `1 <= words[i].length, result.length <= 7`
*   `words[i], result` contains only upper case English letters.
*   Number of different characters used on the expression is at most 10.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<char, int> m;
    vector<int> v;

    bool isSolvable(vector<string>& words, string result) {
        //words.push_back(result);
        for(auto &w : words) {
            reverse(w.begin(), w.end());
            if(w.size() > result.size())
                return false;
        }
        reverse(result.begin(), result.end());
        v.resize(128);
        for(auto &n: v) n = -1;
        return dfs(0, 0, words, result, 0);
    }
    
    bool dfs(int col, int row, vector<string>& words, string &result, int sum) {
        if(col >= result.size()) {
            return sum == 0 && v[result.back()] != 0;
        }
        if(row == words.size()) {
            int mod = sum % 10;
            int rc = result[col];
            if(v[rc] >= 0) {
                if(mod != v[rc])
                    return false;
            }else if(m[mod])
                return false;
            int srm = m[mod], srv = v[rc];
            m[mod] = 1;
            v[rc] = mod;
            if(dfs(col + 1, 0, words, result, sum / 10))
                return true;
            m[mod] = srm;
            v[rc] = srv;
            return false;
        }
        if(col >= words[row].size()) {
            return dfs(col, row + 1, words, result, sum);
        }
        int ch = words[row][col];
        if(v[ch] >= 0) {
            sum += v[ch];
            return dfs(col, row + 1, words, result, sum);
        }
        for(int i = (col + 1 == words[row].size() ? 1 : 0); i <= 9; ++i) {
            if(m[i]) continue;
            m[i] = 1;
            v[ch] = i;
            if(dfs(col, row+1, words, result, i + sum)) return true;
            m[i] = 0;
            v[ch] = -1;
        }
        return false;
    }
};
```
      