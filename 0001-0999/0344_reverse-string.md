[344.reverse-string](https://leetcode.com/problems/reverse-string/)  

Write a function that reverses a string. The input string is given as an array of characters `char[]`.

Do not allocate extra space for another array, you must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

You may assume all the characters consist of [printable ascii characters](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

**Example 1:**

  
**Input:** \["h","e","l","l","o"\]
  
**Output:** \["o","l","l","e","h"\]
  

**Example 2:**

  
**Input:** \["H","a","n","n","a","h"\]
  
**Output:** \["h","a","n","n","a","H"\]  



**Solution:**  

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = (int)s.size() - 1;
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
```
      