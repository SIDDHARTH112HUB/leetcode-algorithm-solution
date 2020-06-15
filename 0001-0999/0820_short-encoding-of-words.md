[820.short-encoding-of-words](https://leetcode.com/problems/short-encoding-of-words/)  

Given a list of words, we may encode it by writing a reference string `S` and a list of indexes `A`.

For example, if the list of words is `["time", "me", "bell"]`, we can write it as `S = "time#bell#"` and `indexes = [0, 2, 5]`.

Then for each index, we will recover the word by reading from the reference string from that index until we reach a `"#"` character.

What is the length of the shortest reference string S possible that encodes the given words?

**Example:**

**Input:** words = `["time", "me", "bell"]`
**Output:** 10
**Explanation:** S = `"time#bell#" and indexes = [0, 2, 5`\].

**Note:**

1.  `1 <= words.length <= 2000`.
2.  `1 <= words[i].length <= 7`.
3.  Each word has only lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for( auto &w:words){
            for( int i = 1; i < w.length(); i++ ){
                s.erase(w.substr(i));
            }
        }
        int ans = 0;
        for(auto &str:s){
            ans += str.length()+1;
        }
        return ans;
    }
};
```
      