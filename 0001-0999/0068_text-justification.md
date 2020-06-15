[68.text-justification](https://leetcode.com/problems/text-justification/)  

Given an array of words and a width _maxWidth_, format the text such that each line has exactly _maxWidth_ characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly _maxWidth_ characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no **extra** space is inserted between words.

**Note:**

*   A word is defined as a character sequence consisting of non-space characters only.
*   Each word's length is guaranteed to be greater than 0 and not exceed _maxWidth_.
*   The input array `words` contains at least one word.

**Example 1:**

**Input:**
words = \["This", "is", "an", "example", "of", "text", "justification."\]
maxWidth = 16
**Output:**
\[
   "This    is    an",
   "example  of text",
   "justification.  "
\]

**Example 2:**

**Input:**
words = \["What","must","be","acknowledgment","shall","be"\]
maxWidth = 16
**Output:**
\[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
\]
**Explanation:** Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

**Example 3:**

**Input:**
words = \["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"\]
maxWidth = 20
**Output:**
\[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int prev = 0, cur= 0, len=0,cnt =0;
        words.push_back("");
        for(int i = 0; i<words.size(); i++){
            len += words[i].size();
            if( len + cnt + words[i+1].size()+1 <= maxWidth &&  i+1 != words.size()){
                cnt++;
            }else{
                if( i+1 == words.size() ){
                    if( cnt == 0 )
                        break;
                    else
                        cnt--;
                }
                string res = "";
                int space_cnt = 0;
                int space_mod = 0;
                if( cnt > 0){
                    space_cnt = (maxWidth-len)/cnt;
                    space_mod = (maxWidth-len)%cnt;
                }else{
                    space_cnt = maxWidth-len;
                }
                if( i+1 == words.size() ){
                    if( len < maxWidth)
                        space_cnt = 1;
                    else
                        space_cnt = 0;
                    space_mod = 0;
                }
                for( int j = prev; j<=prev+cnt; j++){
                    res += words[j];
                    if( space_cnt > 0 && (cnt == 0 || j<prev+cnt))
                        res += string(space_cnt, ' ');
                    if( space_mod-- > 0 )
                        res += ' ';
                }
                if( i+1 == words.size() ){
                    if( res.size() < maxWidth ){
                        res += string(maxWidth-res.size(), ' ');
                    }
                }
                ans.push_back(res);
                prev = i+1;
                len = 0;
                cnt = 0;
            }
        }
        return ans;
    }
};
```
      