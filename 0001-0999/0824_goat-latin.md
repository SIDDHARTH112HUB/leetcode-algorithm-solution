[824.goat-latin](https://leetcode.com/problems/goat-latin/)  

A sentence `S` is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "_Goat Latin"_ (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

*   If a word begins with a vowel (a, e, i, o, or u), append `"ma"` to the end of the word.  
    For example, the word 'apple' becomes 'applema'.  
     
*   If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add `"ma"`.  
    For example, the word `"goat"` becomes `"oatgma"`.  
     
*   Add one letter `'a'` to the end of each word per its word index in the sentence, starting with 1.  
    For example, the first word gets `"a"` added to the end, the second word gets `"aa"` added to the end and so on.

Return the final sentence representing the conversion from `S` to Goat Latin. 

**Example 1:**

  
**Input:** "I speak Goat Latin"
  
**Output:** "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
  

**Example 2:**

  
**Input:** "The quick brown fox jumped over the lazy dog"
  
**Output:** "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
  

Notes:

*   `S` contains only uppercase, lowercase and spaces. Exactly one space between each word.
*   `1 <= S.length <= 150`.  



**Solution:**  

```python3
class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        word_list = S.split(" ")
        vowel = {"a":1, "e":1, "i":1, "o":1,"u":1 ,"A":1, "E":1, "I":1, "O":1,"U":1}
        ans_list = []
        for idx, word in enumerate(word_list):
            if vowel.get(word[0]):
                ans_list.append(word + "ma" + "a"*(idx+1))
            else:
                ans_list.append(word[1:] + word[0] +"ma" + "a"*(idx+1))
        return " ".join(ans_list)
```
      