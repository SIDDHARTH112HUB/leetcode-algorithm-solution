[949.largest-time-for-given-digits](https://leetcode.com/problems/largest-time-for-given-digits/)  

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

**Example 1:**

  
**Input:** \[1,2,3,4\]
  
**Output:** "23:41"
  

**Example 2:**

  
**Input:** \[5,5,5,5\]
  
**Output:** ""
  

**Note:**

1.  `A.length == 4`
2.  `0 <= A[i] <= 9`  



**Solution:**  

```cpp
class Solution {
public:
    int ans = -1;
    string largestTimeFromDigits(vector<int>& A) {
        dfs(A, 0, 0, 0);
        if( ans == -1 )
            return ""; 
        string h = to_string(ans >> 8);
        if( h.size() == 1 )
            h = "0"+h;
        string m = to_string( ans & 0xFF);
        if( m.size() == 1 )
            m = "0"+m;
        return h + ":" + m;
    }
    void dfs( vector<int>& A, int h, int m, int cnt){
        if( cnt >= 4 ){
            ans = max(ans, (h<<8)+m);
            return;
        }
        for( int i = 0; i< A.size(); i++){
            if( A[i] == -1) continue;
            int src = A[i];
            if( h*10 + A[i] <24){
                int newh = h*10 + A[i];
                A[i] = -1;
                dfs( A, newh, m, cnt+1);
                A[i] = src;
            }else if( m *10 + A[i] < 60 ){
                int newm = m*10 + A[i];
                A[i] = -1;
                dfs( A, h, newm, cnt+1);
                A[i] = src;
            }
        }
    }
};
```
      