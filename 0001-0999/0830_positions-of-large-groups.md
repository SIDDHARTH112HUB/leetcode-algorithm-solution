[830.positions-of-large-groups](https://leetcode.com/problems/positions-of-large-groups/)  

In a string `S` of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like `S = "abbxxxxzyy"` has the groups `"a"`, `"bb"`, `"xxxx"`, `"z"` and `"yy"`.

Call a group _large_ if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

**Example 1:**

**Input:** "abbxxxxzzy"
**Output:** \[\[3,6\]\]
**Explanation**: `"xxxx" is the single` large group with starting  3 and ending positions 6.

**Example 2:**

**Input:** "abc"
**Output:** \[\]
**Explanation**: We have "a","b" and "c" but no large group.

**Example 3:**

**Input:** "abcdddeeeeaabbbcd"
**Output:** \[\[3,5\],\[6,9\],\[12,14\]\]

**Note:**  `1 <= S.length <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char prev = ' ';
        int last = 0;
        int cnt = 1;
        int idx=0;
        vector< vector<int> > ans;
        for( char c : S){
            if( prev == c ){
                cnt++;
            }else{
                if( cnt >= 3 ){
                    ans.push_back({last, idx-1});
                }
                prev = c;
                cnt = 1;
                last = idx;
            }
            idx++;
        }
        if( cnt >= 3 ){
            ans.push_back({last, idx-1});
        }
        return ans;
    }
};
```
      