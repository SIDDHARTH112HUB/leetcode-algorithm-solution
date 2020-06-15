[884.uncommon-words-from-two-sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/)  

We are given two sentences `A` and `B`.  (A _sentence_ is a string of space separated words.  Each _word_ consists only of lowercase letters.)

A word is _uncommon_ if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

**Example 1:**

**Input:** A = "this apple is sweet", B = "this apple is sour"
**Output:** \["sweet","sour"\]

**Example 2:**

**Input:** A = "apple apple", B = "banana"
**Output:** \["banana"\]

**Note:**

1.  `0 <= A.length <= 200`
2.  `0 <= B.length <= 200`
3.  `A` and `B` both contain only spaces and lowercase letters.  



**Solution:**  

```python3
class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        a = set()
        b = set()
        da = {}
        for s in A.split(" "):
            a.add(s)
            da[s] = da.get(s,0)+1
            
        for s in B.split(" "):
            b.add(s)
            da[s] = da.get(s,0)+1
            
        for k,v in da.items():
            if v > 1:
                if k in a:
                    a.remove(k)
                if k in b:
                    b.remove(k)
        
        return list(a ^ b)
```
      