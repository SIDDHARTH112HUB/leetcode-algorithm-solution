[411.minimum-unique-word-abbreviation](https://leetcode.com/problems/minimum-unique-word-abbreviation/)  

A string such as `"word"` contains the following abbreviations:

\["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"\]
  

Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the **_smallest possible_** length such that it does not conflict with abbreviations of the strings in the dictionary.

Each **number** or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

**Note:**  

*   In the case of multiple answers as shown in the second example below, you may return any one of them.
*   Assume length of target string = **m**, and dictionary size = **n**. You may assume that **m ≤ 21**, **n ≤ 1000**, and **log2(n) + m ≤ 20**.

**Examples:**  

  
"apple", \["blade"\] -> "a4" (because "5" or "4e" conflicts with "blade")
  

  
"apple", \["plain", "amber", "blade"\] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").  



**Solution:**  

```cpp
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if(dictionary.size() == 0) return to_string(target.size());
        vector<string> items;
        generate(target, 0, 0, "", items);
        sort(items.begin(), items.end(), [](auto &a, auto &b){
            return a.size() < b.size();
        });
        for(auto &str : items) {
            bool res = true;
            for(auto &d : dictionary) {
                if(d.size() != target.size()) continue;
                if(valid(str, d)){
                    res = false;
                    break;
                }
            }
            if(res) return str;
        }
        return "";
    }
    
    bool valid(string &str, string d) {
        int j = 0;
        int size = 0;
        bool f = false;
        string nd;
        for(int i = 0; i < str.size(); ++i) {
            int c = str[i];
            if(c >= 0 && c <= '9') {
                size = size * 10 + c - '0';
                nd += c;
            }
            else {
                if(size > 0)
                    j += size;
                
                if(j >= d.size()) return false;
                nd += d[j];
                ++j;
                size = 0;
            }
        }
        return nd == str;
    }
    void generate(string &target, int i, int cnt, string str, vector<string> &items) {
        if(i >= target.size()) {
            items.push_back(str + (cnt > 0 ? to_string(cnt) : ""));
            return;
        }
        generate(target, i + 1, cnt + 1, str, items);
        generate(target, i + 1, 0, str + (cnt > 0 ? to_string(cnt) : "") + target[i], items);
    }
};
```
      