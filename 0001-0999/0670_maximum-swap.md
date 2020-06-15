[670.maximum-swap](https://leetcode.com/problems/maximum-swap/)  

Given a non-negative integer, you could swap two digits **at most** once to get the maximum valued number. Return the maximum valued number you could get.

**Example 1:**  

**Input:** 2736
**Output:** 7236
**Explanation:** Swap the number 2 and the number 7.

**Example 2:**  

**Input:** 9973
**Output:** 9973
**Explanation:** No swap.

**Note:**  

1.  The given number is in the range \[0, 108\]  



**Solution:**  

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int ans = num;
        for( int i = 0; i<str.size(); i++){
            for( int j = i+1; j<str.size(); j++){
                swap(str[i], str[j]);
                ans = max( stoi(str), ans) ;
                swap(str[i], str[j]);
            }
        }
        return ans;
    }
};
```
      