[249.group-shifted-strings](https://leetcode.com/problems/group-shifted-strings/)  

Given a string, we can "shift" each of its letter to its successive letter, for example: `"abc" -> "bcd"`. We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

**Example:**

**Input:** `["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],`
**Output:** 
\[
  \["abc","bcd","xyz"\],
  \["az","ba"\],
  \["acef"\],
  \["a","z"\]
\]  



**Solution:**  

```cpp
/**
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            bool b = false;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (isShifted(it->first, a)) {
                    it->second.insert(a);
                    b = true;
                }
            }
            if (!b) m[a] = {a};
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
    bool isShifted(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int diff = (s1[0] + 26 - s2[0]) % 26;
        for (int i = 1; i < s1.size(); ++i) {
            if ((s1[i] + 26 - s2[i]) % 26 != diff) return false;
        }
        return true;
    }
}; 

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            string t = "";
            for (char c : a) {
                t += to_string((c + 26 - a[0]) % 26) + ",";
            }
            m[t].insert(a);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};
*/
class Solution {
public:
    ////not good
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, string> m;
        map<string, vector<string> > group;
        int idx = 0;
        // cout<<"begin"<<endl;
        vector<vector<string> > ans;
        set<string> v(strings.begin(), strings.end());
        for(auto str : strings) {
            if(m.count(str)) {
                group[m[str]].push_back(str);
                continue;
            }
            m[str] = str;
            group[str].push_back(str);
            // ans.push_back({str});
            for(int i = 1; i < 26; ++i) {
                if(i == 0) continue;
                string ns = str;
                bool f = true;
                for(auto &c : ns) {
                    int x = c;
                    x += i;
                    if(x > 'z'){
                        c = 'a' + (x - 'z' - 1);
                    }else
                        c = x;
                }
                if(f) {
                    m[ns] = str;
                    // if(v.count(ns))
                    //     ans.back().push_back(ns);
                }
            }
        }
        // for(auto it : m) {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(auto &it : group) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
```
      