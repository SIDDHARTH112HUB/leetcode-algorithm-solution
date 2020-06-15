[748.shortest-completing-word](https://leetcode.com/problems/shortest-completing-word/)  

Find the minimum length word from a given dictionary `words`, which has all the letters from the string `licensePlate`. Such a word is said to _complete_ the given string `licensePlate`

Here, for letters we ignore case. For example, `"P"` on the `licensePlate` still matches `"p"` on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a `licensePlate` of `"PP"`, the word `"pair"` does not complete the `licensePlate`, but the word `"supper"` does.

**Example 1:**  

**Input:** licensePlate = "1s3 PSt", words = \["step", "steps", "stripe", "stepple"\]
**Output:** "steps"
**Explanation:** The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

**Example 2:**  

**Input:** licensePlate = "1s3 456", words = \["looks", "pest", "stew", "show"\]
**Output:** "pest"
**Explanation:** There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.

**Note:**  

1.  `licensePlate` will be a string with length in range `[1, 7]`.
2.  `licensePlate` will contain digits, spaces, or letters (uppercase or lowercase).
3.  `words` will have a length in the range `[10, 1000]`.
4.  Every `words[i]` will consist of lowercase letters, and have length in range `[1, 15]`.  



**Solution:**  

```python
class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        letter_dict = {};
        for i in licensePlate:
            i = i.lower();
            if( i>="a" and i <="z"):
                letter_dict[i] = letter_dict.get(i, 0) + 1;
        #print(letter_dict)
        max_len = 1000000000;
        for word in words:
            item = {}
            for c in word:
                item[c.lower()] = item.get(c.lower(), 0)+1
            #print(item)
            for key, cnt in letter_dict.items():
                if( cnt > item.get(key, 0) ):
                    break;
            else:
                if( max_len > len(word)):
                    max_len = len(word)
                    ans = word
        return ans
```
      