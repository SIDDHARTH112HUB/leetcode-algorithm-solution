[648.replace-words](https://leetcode.com/problems/replace-words/)  

In English, we have a concept called `root`, which can be followed by some other words to form another longer word - let's call this word `successor`. For example, the root `an`, followed by `other`, which can form another word `another`.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the `successor` in the sentence with the `root` forming it. If a `successor` has many `roots` can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

**Example 1:**

  
**Input:** dict = \["cat","bat","rat"\], sentence = "the cattle was rattled by the battery"  
**Output:** "the cat was rat by the bat"  

**Constraints:**

*   The input will only have lower-case letters.
*   `1 <= dict.length <= 1000`
*   `1 <= dict[i].length <= 100`
*   1 <= sentence words number <= 1000
*   1 <= sentence words length <= 1000  



**Solution:**  

```python
class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        dict.sort();
        root = {dict[0]:dict[0]}
        for word in dict:
            for k, v in root.items():
                if( word.startswith(k)):
                    root[word] = k
                    break;
            else:
                root[word] = word
        #print( root )

        word_list = sentence.split(" ")
        root_list = []
        for word in word_list:
            root_word = root.get(word)
            if( root_word ):
                root_list.append(root_word)
            else:
                for k,v in root.items():
                    if( word.startswith(k)):
                        root[word] = v
                        root_list.append(v)
                        break;
                else:
                    #root[word] = word
                    root_list.append(word)
        
        return " ".join(root_list)
```
      