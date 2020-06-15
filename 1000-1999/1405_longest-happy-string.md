[1405.longest-happy-string](https://leetcode.com/problems/longest-happy-string/)  

A string is called _happy_ if it does not have any of the strings `'aaa'`, `'bbb'` or `'ccc'` as a substring.

Given three integers `a`, `b` and `c`, return **any** string `s`, which satisfies following conditions:

*   `s` is _happy_ and longest possible.
*   `s` contains **at most** `a` occurrences of the letter `'a'`, **at most** `b` occurrences of the letter `'b'` and **at most** `c` occurrences of the letter `'c'`.
*   `s` will only contain `'a'`, `'b'` and `'c'` letters.

If there is no such string `s` return the empty string `""`.

**Example 1:**

**Input:** a = 1, b = 1, c = 7
**Output:** "ccaccbcc"
**Explanation:** "ccbccacc" would also be a correct answer.

**Example 2:**

**Input:** a = 2, b = 2, c = 1
**Output:** "aabbc"

**Example 3:**

**Input:** a = 7, b = 1, c = 0
**Output:** "aabaa"
**Explanation:** It's the only correct answer in this case.

**Constraints:**

*   `0 <= a, b, c <= 100`
*   `a + b + c > 0`  



**Solution:**  

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int> > pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        string ans;
        while(pq.size() > 1) {
            auto p1 = pq.top();pq.pop();
            auto p2 = pq.top();pq.pop();
            ans += p1.second;
            --p1.first;
            if(p1.first > 0 && p1.first > p2.first) {
                ans+= p1.second;
                --p1.first;
            }
            ans += p2.second;
            --p2.first;
            if(p1.first > 0)
                pq.push(p1);
            if(p2.first > 0)
                pq.push(p2);
        }
        if(pq.size()) {
            auto p1 = pq.top();
            for(int i = 0; i < 2 && p1.first > 0; ++i) {
                ans+= p1.second;
                --p1.first;
            }
        }
        return ans;
    }
};
```
      