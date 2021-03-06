[1023.camelcase-matching](https://leetcode.com/problems/camelcase-matching/)  

A query word matches a given `pattern` if we can insert **lowercase** letters to the pattern word so that it equals the `query`. (We may insert each character at any position, and may insert 0 characters.)

Given a list of `queries`, and a `pattern`, return an `answer` list of booleans, where `answer[i]` is true if and only if `queries[i]` matches the `pattern`.

**Example 1:**

  
**Input:** queries = \["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"\], pattern = "FB"
  
**Output:** \[true,false,true,true,false\]
  
**Explanation:** 
  
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
  
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
  
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

**Example 2:**

  
**Input:** queries = \["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"\], pattern = "FoBa"
  
**Output:** \[true,false,true,false,false\]
  
**Explanation:** 
  
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
  
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
  

**Example 3:**

  
**Input:** queries = \["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"\], pattern = "FoBaT"
  
**Output:** \[false,true,false,false,false\]
  
**Explanation:** 
  
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
  

**Note:**

1.  `1 <= queries.length <= 100`
2.  `1 <= queries[i].length <= 100`
3.  `1 <= pattern.length <= 100`
4.  All strings consists only of lower and upper case English letters.  



**Solution:**  

```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto &q : queries) {
            int i = 0, j = 0;
            bool res = true;
            while(i < q.size()) {
                if( j>= pattern.size()) {
                    if(q[i] <= 'Z') {
                        break;
                    }
                    ++i;
                    continue;
                }
                if(q[i] == pattern[j]) {
                    ++i; ++j;
                }else {
                    if(q[i] >= 'a'){
                        ++i;
                    }else{
                        break;
                    }
                }
                
            }
            ans.push_back(i == q.size() && j == pattern.size());
        }
        return ans;
    }
};
```
      