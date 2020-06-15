[17.letter-combinations-of-a-phone-number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)  

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example:**

**Input:** "23"
**Output:** \["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"\].

**Note:**

Although the above answer is in lexicographical order, your answer could be in any order you want.  



**Solution:**  

```cpp
class Solution {
public:
    void combine(vector<string>& ans, string& digits, int idx, char* item){
        if( digits[idx] == '\0' ){
            item[idx] = '\0';
            ans.push_back(item);
            return;
        }
        static char* letter_arr[10] = {
            "","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        char* letter_str = (char*)letter_arr[digits[idx]-'0'];
        while(*letter_str !='\0'){
            item[idx] = *letter_str;
            this->combine(ans, digits, idx+1,item);
            letter_str++;
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if( digits.size() == 0 ) return ans;
        char ans_item[100];
        this->combine(ans, digits, 0, ans_item);
        return ans;
    }
};
```
      