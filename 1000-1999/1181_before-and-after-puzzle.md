[1181.before-and-after-puzzle](https://leetcode.com/problems/before-and-after-puzzle/)  

Given a list of `phrases`, generate a list of Before and After puzzles.

A _phrase_ is a string that consists of lowercase English letters and spaces only. No space appears in the start or the end of a phrase. There are no consecutive spaces in a phrase.

_Before and After puzzles_ are phrases that are formed by merging two phrases where the **last word of the first phrase** is the same as the **first word of the second phrase**.

Return the Before and After puzzles that can be formed by every two phrases `phrases[i]` and `phrases[j]` where `i != j`. Note that the order of matching two phrases matters, we want to consider both orders.

You should return a list of **distinct** strings **sorted lexicographically**.

**Example 1:**

  
**Input:** phrases = \["writing code","code rocks"\]  
**Output:** \["writing code rocks"\]  

**Example 2:**

  
**Input:** phrases = \["mission statement",  
                  "a quick bite to eat",  
                  "a chip off the old block",  
                  "chocolate bar",  
                  "mission impossible",  
                  "a man on a mission",  
                  "block party",  
                  "eat my words",  
                  "bar of soap"\]  
**Output:** \["a chip off the old block party",  
         "a man on a mission impossible",  
         "a man on a mission statement",  
         "a quick bite to eat my words",  
         "chocolate bar of soap"\]  

**Example 3:**

  
**Input:** phrases = \["a","b","a"\]  
**Output:** \["a"\]  

**Constraints:**

*   `1 <= phrases.length <= 100`
*   `1 <= phrases[i].length <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<pair<string, int> > > last, first;
        for(int k = 0; k < phrases.size(); ++k) {
            string str = phrases[k];
            //cout<<"str: "<<str<<endl;
            str += ' ';
            for(int i = 0; i < str.size(); ++i) {
                if(str[i] == ' ' || i == str.size() - 1) {
                    string s1 = str.substr(0, i);
                    string s2 = str.substr(i + 1, str.size() - 1);
                    first[s1].push_back({s2, k});
                    //cout<<"first "<<s1<<endl;
                    break;
                }
            }
            str.pop_back();
            str = " " + str;
            for(int i = str.size()-1; i >= 0; --i) {
                if(str[i] == ' ' || i == 0) {
                    string s1 = str.substr(i+1); 
                    string s2 = str.substr(1);
                    last[s1].push_back({s2, k});
                    //cout<<"last "<<s1<<endl;
                    break;
                }
            }
        }
        set<string> ans;
        for(auto &it : last) {
            string str = it.first;
            for(auto &p : it.second) {
                int i1 = p.second;
                string &l = p.first;
                for(auto &p2 : first[str]){
                    int i2 = p2.second;
                    if(i1 == i2) continue;
                    string &r = p2.first;
                    string res = l + " " + r;
                    if(res.back() == ' ')
                        res.pop_back();
                    //if(res == "")
                    //    res = str;
                    ans.insert(res);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
```
      