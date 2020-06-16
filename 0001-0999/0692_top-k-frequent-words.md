[692.top-k-frequent-words](https://leetcode.com/problems/top-k-frequent-words/)  

Given a non-empty list of words, return the _k_ most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

**Example 1:**  

  
**Input:** \["i", "love", "leetcode", "i", "love", "coding"\], k = 2
  
**Output:** \["i", "love"\]
  
**Explanation:** "i" and "love" are the two most frequent words.
  
    Note that "i" comes before "love" due to a lower alphabetical order.
  

**Example 2:**  

  
**Input:** \["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"\], k = 4
  
**Output:** \["the", "is", "sunny", "day"\]
  
**Explanation:** "the", "is", "sunny" and "day" are the four most frequent words,
  
    with the number of occurrence being 4, 3, 2 and 1 respectively.
  

**Note:**  

1.  You may assume _k_ is always valid, 1 ≤ _k_ ≤ number of unique elements.
2.  Input words contain only lowercase letters.

**Follow up:**  

1.  Try to solve it in _O_(_n_ log _k_) time and _O_(_n_) extra space.  



**Solution:**  

```python
class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        if( k == 0 ):
            return []
        from collections import Counter
        import operator
        count = [(v,key) for key, v in Counter(words).items()]
        def func(x, y):
            if( x[0]>y[0] ):
                return 1
            if( x[0]<y[0] ):
                return -1
            if(x[0] == y[0]):
                if x[1]<y[1] :
                    return 1
                else:
                    return -1;
            return 0
        count.sort(cmp=func, reverse=True)
        return [word for cnt, word in count[0:k]]
```
      