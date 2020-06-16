[1073.adding-two-negabinary-numbers](https://leetcode.com/problems/adding-two-negabinary-numbers/)  

Given two numbers `arr1` and `arr2` in base **\-2**, return the result of adding them together.

Each number is given in _array format_:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, `arr = [1,1,0,1]` represents the number `(-2)^3 + (-2)^2 + (-2)^0 = -3`.  A number `arr` in _array format_ is also guaranteed to have no leading zeros: either `arr == [0]` or `arr[0] == 1`.

Return the result of adding `arr1` and `arr2` in the same format: as an array of 0s and 1s with no leading zeros.

**Example 1:**

  
**Input:** arr1 = \[1,1,1,1,1\], arr2 = \[1,0,1\]  
**Output:** \[1,0,0,0,0\] **Explanation:** arr1 represents 11, arr2 represents 5, the output represents 16.  

**Note:**

1.  `1 <= arr1.length <= 1000`
2.  `1 <= arr2.length <= 1000`
3.  `arr1` and `arr2` have no leading zeros
4.  `arr1[i]` is `0` or `1`
5.  `arr2[i]` is `0` or `1`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        vector<int> res;
        int c = 0, i = 0, j = 0, d = 0;
        while( i < arr1.size() || j < arr2.size() || c != 0 || d != 0) {
            int a = i < arr1.size() ? arr1[i] : 0;
            int b = j < arr2.size() ? arr2[j] : 0;
            int s = (a + b) * (i % 2 ? -1 : 1) + c + d;
            res.push_back(abs(s%2));
            if(s % 2 != (i % 2 ? -1 : 1))
                d = (s % 2);
            else 
                d = 0;
            c = s / 2;
            ++j, ++i;
        }
        if(res.size() == 0) return {0};
        while(res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
```
      