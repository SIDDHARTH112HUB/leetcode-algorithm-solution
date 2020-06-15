[616.add-bold-tag-in-string](https://leetcode.com/problems/add-bold-tag-in-string/)  

Given a string **s** and a list of strings **dict**, you need to add a closed pair of bold tag `<b>` and `</b>` to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

**Example 1:**

**Input:** 
s = "abcxyz123"
dict = \["abc","123"\]
**Output:**
"<b>abc</b>xyz<b>123</b>"

**Example 2:**

**Input:** 
s = "aaabbcc"
dict = \["aaa","aab","bc"\]
**Output:**
"<b>aaabbc</b>c"

**Constraints:**

*   The given dict won't contain duplicates, and its length won't exceed 100.
*   All the strings in input have length in range \[1, 1000\].

**Note:** This question is the same as 758: [https://leetcode.com/problems/bold-words-in-string/](https://leetcode.com/problems/bold-words-in-string/)  



**Solution:**  

```cpp
struct Trie {
    
};
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> arr(s.size());
        for(auto &str : dict) {
            int pos = 0;
            while((pos = s.find(str, pos)) != string::npos) {
                for(int i = pos; i < str.size() + pos; ++i) {
                    arr[i] = true;
                }
                pos += 1;
            }
        }
        string ans;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] == true) {
                if(i == 0 || arr[i-1] == false)
                    ans += "<b>";
            }else if(i > 0){
                if(arr[i-1] == true )
                    ans += "</b>";
            }
            ans += s[i];
        }
        if(arr.back() == true)
            ans += "</b>";
        return ans;
    }
};
```
      