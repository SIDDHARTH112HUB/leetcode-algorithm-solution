[527.word-abbreviation](https://leetcode.com/problems/word-abbreviation/)  

Given an array of n distinct non-empty strings, you need to generate **minimal** possible abbreviations for every word following rules below.

1.  Begin with the first character and then the number of characters abbreviated, which followed by the last character.
2.  If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
3.  If the abbreviation doesn't make the word shorter, then keep it as original.

**Example:**  

**Input:** \["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"\]
**Output:** \["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"\]

**Note:**

1.  Both n and the length of each word will not exceed 400.
2.  The length of each word is greater than 1.
3.  The words consist of lowercase English letters only.
4.  The return answers should be **in the same order** as the original array.  



**Solution:**  

```cpp

class Solution {
public:
    vector<string> ans;
    map<string, vector<pair<string, int> > > m;
    string abbr(const string &s, int len) {
        if(s.size() <= 3) return s;
        auto str = s.substr(0, len) + to_string(s.size() - len - 1) + s.substr(s.size() - 1);
        if(str.size() == s.size()) return s;
        return str;
    }
    vector<string> wordsAbbreviation(vector<string>& d) {
        vector<string> ans(d.size());
        map<string, int> dict;
        for(int i = 0; i < d.size(); ++i) {
            dict[d[i]] = i;
        }
        
        int len = 1;
        
        while(dict.size()) {
            int idx = 0;
            for(const auto &it : dict) {
                auto &originString = it.first;
                auto index = it.second;
                auto ns = abbr(originString, len);
                m[ns].push_back({originString, index});
            }
            for(auto &it : m) {
                auto &arr = it.second;
                auto &originString = it.second[0].first;
                auto &shortString = it.first;
                int stringIdx = it.second[0].second;
                if(arr.size() == 1) {
                    ans[stringIdx] = shortString;
                    dict.erase(originString);
                }
            }
            m.clear();
            ++len;
        }
        
        return ans;
    }
};
```
      