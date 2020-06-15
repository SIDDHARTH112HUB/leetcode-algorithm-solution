[6.zigzag-conversion](https://leetcode.com/problems/zigzag-conversion/)  

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

**Example 1:**

**Input:** s = "PAYPALISHIRING", numRows = 3
**Output:** "PAHNAPLSIIGYIR"

**Example 2:**

**Input:** s = "PAYPALISHIRING", numRows = 4
**Output:** "PINALSIGYAHRPI"
**Explanation:**

P     I    N
A   L S  I G
Y A   H R
P     I  



**Solution:**  

```cpp
class Solution {
public:
    string convert(string s, int nRows) {
        if( nRows <= 1) return s;
        string res="";
        int len = s.length();
        if( len <= 1 ) return s;
        int step = (nRows-1)*2;
        for( int i = 0; i<nRows; i++)
        {
            int cnt = 0;
            do
            {
                int idx = i + step*cnt;
                int idx2= i + step*cnt + (nRows-i%nRows-1)*2;
                if( idx < len)
                    res += s.at(idx);
                else
                    break;
                if(idx2<len && i!=0 && i!=(nRows-1))
                    res += s.at(idx2);
                ++cnt;
                    
            }while(true);
        }
        return res;
    }
};
```
      