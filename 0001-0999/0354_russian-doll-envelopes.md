[354.russian-doll-envelopes](https://leetcode.com/problems/russian-doll-envelopes/)  

You have a number of envelopes with widths and heights given as a pair of integers `(w, h)`. One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

**Note:**  
Rotation is not allowed.

**Example:**

  
**Input:** \[\[5,4\],\[6,4\],\[6,7\],\[2,3\]\]
  
**Output:** 3 
  
**Explanation: T**he maximum number of envelopes you can Russian doll is `3` (\[2,3\] => \[5,4\] => \[6,7\]).  



**Solution:**  

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if( envelopes.size() == 0 ) return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto&a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        
        int ans = 1;
        for( int i = 0; i< envelopes.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if(it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            }else {
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};
```
      