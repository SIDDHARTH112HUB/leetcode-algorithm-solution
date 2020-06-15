[451.sort-characters-by-frequency](https://leetcode.com/problems/sort-characters-by-frequency/)  

Given a string, sort it in decreasing order based on the frequency of characters.

**Example 1:**

**Input:**
"tree"

**Output:**
"eert"

**Explanation:**
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

**Example 2:**

**Input:**
"cccaaa"

**Output:**
"cccaaa"

**Explanation:**
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

**Example 3:**

**Input:**
"Aabb"

**Output:**
"bbAa"

**Explanation:**
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.  



**Solution:**  

```cpp
class Solution {
public:
    string frequencySort(string s) {
        
        /*int count[256] = {0};
        for(auto &c : s){
            count[c]++;
        }
        sort( s.begin(), s.end(), [&count](char a, char b){
            return (count[a] > count[b]) || (count[a] == count[b] && a<b);
        });
        return s;*/
        
        vector< pair<char, int> > count(256);
        for(char c : s){
            count[c].first = c;
            count[c].second++;
        }
        sort( count.begin(), count.end(), 
             [&count](pair<char, int> &a, pair<char, int> &b){
                return (a.second > b.second);// || (a.second ==b.second  && a.first > b.first);
           });
        string ans;
        for( auto it = count.begin(); it!=count.end(); ++it){
            if( it->second == 0)
                continue;
            ans.append(string(it->second,it->first));
        }
        return ans;
    }
};
```
      