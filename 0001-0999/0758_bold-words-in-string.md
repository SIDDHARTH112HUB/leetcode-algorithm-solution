[758.bold-words-in-string](https://leetcode.com/problems/bold-words-in-string/)  

Given a set of keywords `words` and a string `S`, make all appearances of all keywords in `S` bold. Any letters between `<b>` and `</b>` tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that `words = ["ab", "bc"]` and `S = "aabcd"`, we should return `"a<b>abc</b>d"`. Note that returning `"a<b>a<b>b</b>c</b>d"` would use more tags, so it is incorrect.

**Constraints:**

*   `words` has length in range `[0, 50]`.
*   `words[i]` has length in range `[1, 10]`.
*   `S` has length in range `[0, 500]`.
*   All characters in `words[i]` and `S` are lowercase letters.

**Note:** This question is the same as 616: [https://leetcode.com/problems/add-bold-tag-in-string/](https://leetcode.com/problems/add-bold-tag-in-string/)  



**Solution:**  

```python3
class Solution:
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        seg = []
        for word in words:
            idx = -1
            while( True ):
                idx = S.find(word, idx+1);
                seg.append([idx, idx+len(word)]);
                if( idx < 0 ):
                    break;
        seg.sort();
        print(seg)
        for idx in range(1, len(seg)):
            curseg = seg[idx];
            prevseg = seg[idx-1];
            if( curseg[0] >=0 and prevseg[0]>=0 and curseg[0] <= prevseg[1] ):
                curseg[0] = prevseg[0];
                if( curseg[1] < prevseg[1]):
                    curseg[1] = prevseg[1];
                prevseg[0] = -1
        print(seg)
        l = []
        prev=0;
        for s in seg:
            if( s[0] >= 0 ):
                l.append(S[prev:s[0]])
                l.append("<b>")
                l.append(S[s[0]:s[1]])
                l.append("</b>")
                prev = s[1]
        else:
            l.append(S[prev:len(S)]);
        print(l)
        return "".join(l)
            
```
      