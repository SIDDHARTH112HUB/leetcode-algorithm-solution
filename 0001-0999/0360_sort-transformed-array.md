[360.sort-transformed-array](https://leetcode.com/problems/sort-transformed-array/)  

Given a **sorted** array of integers _nums_ and integer values _a_, _b_ and _c_. Apply a quadratic function of the form f(_x_) = _ax_2 + _bx_ + _c_ to each element _x_ in the array.

The returned array must be in **sorted order**.

Expected time complexity: **O(_n_)**

**Example 1:**

  
**Input:** nums = \[-4,-2,2,4\], a = 1, b = 3, c = 5
  
**Output:** \[3,9,15,33\]
  

**Example 2:**

  
**Input:** nums = \[-4,-2,2,4\], a = \-1, b = 3, c = 5
  
**Output:** \[-23,-5,1,7\]  



**Solution:**  

```cpp
class Solution {
public:
    int a;
    int b;
    int c;
    int sign = 1;
    int getValue(int n) {
        return (a * n* n + b * n + c);
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        this->a = a; this->b = b; this->c =c;
        vector<int> arr(nums.size());
        if(a == 0) {
            for(int i = 0; i < nums.size(); ++i)
                arr[i] = getValue(nums[i]);
            if(b < 0) {
                reverse(arr.begin(), arr.end());
            }
            return arr;
        }
        
        int r = 0, l= 0;
        for(; r < nums.size(); ++r) {
            if(nums[r] >= -b/2/a) break;
        }
        
        this->sign = (a < 0 || (a== 0 && b < 0)) ? -1 : 1;
        int idx = this->sign == -1 ? nums.size() -1 : 0;
        l = r - 1;
        while(l >= 0 || r < nums.size()) {
            int lv = l >= 0 ? getValue(nums[l]) : INT_MIN;
            int rv = r < nums.size() ? getValue(nums[r]) : INT_MIN;
            if(lv == INT_MIN) {
                arr[idx] = rv;
                idx += sign;
                ++r;
                continue;
            }else if(rv == INT_MIN) {
                arr[idx] = lv;
                idx += sign;
                --l;
                continue;
            }
            if(this->sign < 0) {
                if(lv > rv) {
                    arr[idx] = lv;
                    --l;
                }else{
                    arr[idx] = rv;
                    ++r;
                }
            }else {
                if(lv < rv) {
                    arr[idx] = lv;
                    --l;
                }
                else {
                    arr[idx] = rv;
                    ++r;
                }
            }
            idx += sign;
        }
        return arr;
    }
};
```
      