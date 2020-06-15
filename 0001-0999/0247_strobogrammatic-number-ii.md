[247.strobogrammatic-number-ii](https://leetcode.com/problems/strobogrammatic-number-ii/)  

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

**Example:**

**Input:**  n = 2
**Output:** `["11","69","88","96"]`  



**Solution:**  

```cpp
class Solution {
public:
    int n = 0;
    map<int, int> m;
    vector<string> ans;
    vector<string> findStrobogrammatic(int n) {
        this->n = n;
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        vector<char> ch = {'0', '1', '6', '8', '9'};
        string str;
        dfs(ch, 1, str);
        return ans;
    }
    
    void dfs(vector<char> &ch, int idx, string &str) {
        if(str.size() >= n/2) {
            auto r = str;
            reverse(r.begin(), r.end());
            for(auto &c : r)
                c = m[c];
            if(n % 2) {
                ans.push_back(str + "0" + r);
                ans.push_back(str + "1" + r);
                ans.push_back(str + "8" + r);
            }else
                ans.push_back(str + r);
            return;
        }
        for(int i = idx; i < ch.size(); ++i) {
            str += ch[i];
            dfs(ch, 0, str);
            str.pop_back();
        }
    }
};
```
      