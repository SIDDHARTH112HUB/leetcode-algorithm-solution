[1002.find-common-characters](https://leetcode.com/problems/find-common-characters/)  

Given an array `A` of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list **(including duplicates)**.  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

**Example 1:**

  
**Input:** \["bella","label","roller"\]
  
**Output:** \["e","l","l"\]
  

**Example 2:**

  
**Input:** \["cool","lock","cook"\]
  
**Output:** \["c","o"\]
  

**Note:**

1.  `1 <= A.length <= 100`
2.  `1 <= A[i].length <= 100`
3.  `A[i][j]` is a lowercase letter  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<unordered_map<int, int> > m(A.size());
        for(int i = 0; i < A.size(); ++i)
            for(auto c : A[i])
                ++m[i][c];
        vector<string> ans;
        for(int c = 'a'; c <='z'; ++c) {
            int cnt = INT_MAX;
            for(int i  = 0; i < m.size(); ++i)
                cnt = min(cnt, m[i][c]);
            while(cnt-- > 0){
                ans.push_back("");
                ans.back() += c;
            }
        }
        return ans;
    }
};
```
      