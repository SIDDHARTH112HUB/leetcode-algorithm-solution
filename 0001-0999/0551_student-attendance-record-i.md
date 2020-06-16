[551.student-attendance-record-i](https://leetcode.com/problems/student-attendance-record-i/)  

You are given a string representing an attendance record for a student. The record only contains the following three characters:

1.  **'A'** : Absent.
2.  **'L'** : Late.
3.  **'P'** : Present.

A student could be rewarded if his attendance record doesn't contain **more than one 'A' (absent)** or **more than two continuous 'L' (late)**.

You need to return whether the student could be rewarded according to his attendance record.

**Example 1:**  

  
**Input:** "PPALLP"
  
**Output:** True
  

**Example 2:**  

  
**Input:** "PPALLL"
  
**Output:** False  



**Solution:**  

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for(int i = 0; i < s.size(); ++i) {
            A += s[i] == 'A';
            L = s[i] == 'L' ? L + 1 : 0;
            if(L > 2) return false;
        }
        return A <= 1;
    }
};
```
      