[179.largest-number](https://leetcode.com/problems/largest-number/)  

Given a list of non negative integers, arrange them such that they form the largest number.

**Example 1:**

**Input:** `[10,2]`
**Output:** "`210"`

**Example 2:**

**Input:** `[3,30,34,5,9]`
**Output:** "`9534330"`

**Note:** The result may be very large, so you need to return a string instead of an integer.  



**Solution:**  

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        vector<string> str;
        for(int n : nums)
            str.push_back(to_string(n));
        sort(str.begin(), str.end(), [](string &a, string &b){
            
            return a+b > b+a;
        });
        string ans;
        for( string &s:str)
            ans+=s;
        if( ans[0] == '0') return "0";
        return ans;
    }
};
```
      