[556.next-greater-element-iii](https://leetcode.com/problems/next-greater-element-iii/)  

Given a positive **32-bit** integer **n**, you need to find the smallest **32-bit** integer which has exactly the same digits existing in the integer **n** and is greater in value than n. If no such positive **32-bit** integer exists, you need to return -1.

**Example 1:**

  
**Input:** 12
  
**Output:** 21
  

**Example 2:**

  
**Input:** 21
  
**Output:** -1  



**Solution:**  

```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        map<int, int> m;
        for(int i = s.size() - 1; i>=0; --i) {
            int c = s[i];
            auto it = m.upper_bound(c);
            m[c] = i;
            if(it == m.end()) continue;
            swap(s[i], s[it->second]);
            sort(s.begin()+i + 1, s.end());
            return stoll(s) > INT_MAX ? -1 : stoi(s);
        }
        return -1;
    }
};
```
      