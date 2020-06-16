[1202.smallest-string-with-swaps](https://leetcode.com/problems/smallest-string-with-swaps/)  

You are given a string `s`, and an array of pairs of indices in the string `pairs` where `pairs[i] = [a, b]` indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given `pairs` **any number of times**.

Return the lexicographically smallest string that `s` can be changed to after using the swaps.

**Example 1:**

  
**Input:** s = "dcab", pairs = \[\[0,3\],\[1,2\]\]  
**Output:** "bacd"  
**Explaination:**   
Swap s\[0\] and s\[3\], s = "bcad"  
Swap s\[1\] and s\[2\], s = "bacd"  

**Example 2:**

  
**Input:** s = "dcab", pairs = \[\[0,3\],\[1,2\],\[0,2\]\]  
**Output:** "abcd"  
**Explaination: **  
Swap s\[0\] and s\[3\], s = "bcad"  
Swap s\[0\] and s\[2\], s = "acbd"  
Swap s\[1\] and s\[2\], s = "abcd"

**Example 3:**

  
**Input:** s = "cba", pairs = \[\[0,1\],\[1,2\]\]  
**Output:** "abc"  
**Explaination: **  
Swap s\[0\] and s\[1\], s = "bca"  
Swap s\[1\] and s\[2\], s = "bac"  
Swap s\[0\] and s\[1\], s = "abc"  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `0 <= pairs.length <= 10^5`
*   `0 <= pairs[i][0], pairs[i][1] < s.length`
*   `s` only contains lower case English letters.  



**Solution:**  

```cpp
struct UF{
    unordered_map<int, int> m;
    
    int find(int x) {
        if(m.count(x)) {
            return m[x] == x ? x : (m[x] = find(m[x]));
        }
        return m[x] = x;
    }
    void combine(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            m[b] = a;
        }
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_set<int> v;
        UF uf;
        for(auto &p : pairs) {
            uf.combine(p[0], p[1]);
        }
        unordered_map<int, string> m;
        unordered_map<int, int> midx;
        for(int i = 0; i < s.size(); ++i) {
            if(uf.m.count(i)) {
                int g = uf.find(i);
                m[g] += s[i];
            }
        }
        for(auto &it : m) {
            sort(it.second.begin(), it.second.end());
            //reverse(it.second.begin(), it.second.end());
        }
        string ans;
        
        for(int i = 0; i < s.size(); ++i) {
            if(uf.m.count(i)) {
                int g = uf.find(i);
                ans += m[g][midx[g]];
                ++midx[g];
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};
```
      