[1291.sequential-digits](https://leetcode.com/problems/sequential-digits/)  

An integer has _sequential digits_ if and only if each digit in the number is one more than the previous digit.

Return a **sorted** list of all the integers in the range `[low, high]` inclusive that have sequential digits.

**Example 1:**

**Input:** low = 100, high = 300
**Output:** \[123,234\]

**Example 2:**

**Input:** low = 1000, high = 13000
**Output:** \[1234,2345,3456,4567,5678,6789,12345\]

**Constraints:**

*   `10 <= low <= high <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int l;
    int r;
    vector<int> sequentialDigits(int low, int high) {
        l = low, r = high;
        vector<int> ans;
        for(int i = 1; i <= 8; ++i) {
            int n = i;
            int c = i;
            while(n < low && c <= 9) {
                //if(c > 9) break;
                n = n * 10 + (++c);
            }
            //cout<<n<<" c:"<<c<<endl;
            while(n <= high && n >= low && c <= 9) {
                ans.push_back(n);
                n = n * 10 + (++c);
                if( c > 9)break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
};
```
      