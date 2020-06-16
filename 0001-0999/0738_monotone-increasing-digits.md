[738.monotone-increasing-digits](https://leetcode.com/problems/monotone-increasing-digits/)  

Given a non-negative integer `N`, find the largest number that is less than or equal to `N` with monotone increasing digits.

(Recall that an integer has _monotone increasing digits_ if and only if each pair of adjacent digits `x` and `y` satisfy `x <= y`.)

**Example 1:**  

  
**Input:** N = 10
  
**Output:** 9
  

**Example 2:**  

  
**Input:** N = 1234
  
**Output:** 1234
  

**Example 3:**  

  
**Input:** N = 332
  
**Output:** 299
  

**Note:** `N` is an integer in the range `[0, 10^9]`.  



**Solution:**  

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int j = str.size(); 
        for(int i = str.size() - 2; i >= 0; --i) {
            if(str[i]  <= str[i+1]) continue;
            str[i]--;
            j = i+1;
        }
        for(int i = j; i < str.size(); ++i) {
            str[i] = '9';
        }
        return stoi(str);
    }
};
```
      