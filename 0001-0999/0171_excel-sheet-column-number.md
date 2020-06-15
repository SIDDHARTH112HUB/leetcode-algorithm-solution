[171.excel-sheet-column-number](https://leetcode.com/problems/excel-sheet-column-number/)  

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

**Example 1:**

**Input:** "A"
**Output:** 1

**Example 2:**

**Input:** "AB"
**Output:** 28

**Example 3:**

**Input:** "ZY"
**Output:** 701  



**Solution:**  

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        long long sum = 0;
        for( int i = 0; i<len ; i++)
        {
            char a = s.at(i);
            int num = a-'A'+1;
            sum += num*pow(26, len-i-1);
        }
        return sum;
    }
};
```
      