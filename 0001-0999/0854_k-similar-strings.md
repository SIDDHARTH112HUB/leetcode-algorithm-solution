[854.k-similar-strings](https://leetcode.com/problems/k-similar-strings/)  

Strings `A` and `B` are `K`\-similar (for some non-negative integer `K`) if we can swap the positions of two letters in `A` exactly `K` times so that the resulting string equals `B`.

Given two anagrams `A` and `B`, return the smallest `K` for which `A` and `B` are `K`\-similar.

**Example 1:**

  
**Input:** A = "ab", B = "ba"
  
**Output:** 1
  

**Example 2:**

  
**Input:** A = "abc", B = "bca"
  
**Output:** 2
  

**Example 3:**

  
**Input:** A = "abac", B = "baca"
  
**Output:** 2
  

**Example 4:**

  
**Input:** A = "aabc", B = "abca"
  
**Output:** 2

**Note:**

1.  `1 <= A.length == B.length <= 20`
2.  `A` and `B` contain only lowercase letters from the set `{'a', 'b', 'c', 'd', 'e', 'f'}`  



**Solution:**  

```cpp
class Solution {
public:
    int kSimilarity(string A, string B) {
        unordered_set<string> v;
        queue<string> q;
        q.push(A);
        v.insert(A);
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto s = q.front();
                q.pop();
                if(s == B)
                    return step;
                for(int i = 0; i < s.size(); ++i) {
                    if(s[i] == B[i]) continue;
                    for(int j = i + 1; j < B.size(); ++j){
                        if(s[i] == B[j] ) {
                            swap(s[i], s[j]);
                            if(v.count(s) == 0){
                                q.push(s);
                                v.insert(s);
                            }
                            swap(s[i], s[j]);
                        }
                    }
                    break;
                }
            }
            ++step;
        }
        return step;
    }
};
```
      