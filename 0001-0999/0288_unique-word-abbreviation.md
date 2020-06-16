[288.unique-word-abbreviation](https://leetcode.com/problems/unique-word-abbreviation/)  

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

  
a) it                      --> it    (no abbreviation)  
  
     1  
     ↓  
b) d|o|g                   --> d1g  
  
              1    1  1  
     1---5----0----5--8  
     ↓   ↓    ↓    ↓  ↓      
c) i|nternationalizatio|n  --> i18n  
  
              1  
     1---5----0  
     ↓   ↓    ↓  
d) l|ocalizatio|n          --> l10n  
  
Additionally for any string s of size less than or equal to 2 their abbreviation is the same string s.  

Find whether its abbreviation is unique in the dictionary. A word's abbreviation is called _unique_ if any of the following conditions is met:

*   There is no word in `dictionary` such that their abbreviation is equal to the abbreviation of `word`.
*   Else, for all words in `dictionary` such that their abbreviation is equal to the abbreviation of `word` those words are equal to `word`.

**Example 1:**

  
**Input**  
\["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"\]  
\[\[\["deer","door","cake","card"\]\],\["dear"\],\["cart"\],\["cane"\],\["make"\]\]  
**Output**  
\[null,false,true,false,true\]  
  
**Explanation**  
ValidWordAbbr validWordAbbr = new ValidWordAbbr(\["deer", "door", "cake", "card"\]);  
validWordAbbr.isUnique("dear"); // return False  
validWordAbbr.isUnique("cart"); // return True  
validWordAbbr.isUnique("cane"); // return False  
validWordAbbr.isUnique("make"); // return True  

**Constraints:**

*   Each word will only consist of lowercase English characters.  



**Solution:**  

```cpp
class ValidWordAbbr {
public:
    map<string, string> m;
    string abbr(string &d) {
        if(d.size() <= 2) return d;
        return d.substr(0, 1) + to_string(d.size() - 2) + d.substr(d.size() - 1);
    }
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto d : dictionary) {
            string ab  =abbr(d);
            if(m.count(ab) && m[ab] != d){
                m[ab] = "";
            }else
                m[ab] = d;
        }
    }
    
    bool isUnique(string word) {
        string ab = abbr(word);
        return m.count(ab) == 0 || m[ab] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
```
      