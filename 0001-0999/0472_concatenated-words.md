[472.concatenated-words](https://leetcode.com/problems/concatenated-words/)  

Given a list of words (**without duplicates**), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

**Example:**  

  
**Input:** \["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"\]
  

  
**Output:** \["catsdogcats","dogcatsdog","ratcatdogcat"\]
  

  
**Explanation:** "catsdogcats" can be concatenated by "cats", "dog" and "cats";   
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";   
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
  

**Note:**  

1.  The number of elements of the given array will not exceed `10,000`
2.  The length sum of elements in the given array will not exceed `600,000`.
3.  All the input string will only include lower case letters.
4.  The returned elements order does not matter.  



**Solution:**  

```cpp


int cmp(string& a, string& b){
    return a.size() < b.size();
}

class Solution {
public:
    unordered_map<string, int> appear;
    vector<string> ans;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        //set<string> word_set(words.begin(), words.end());
        //for( int i = 0; i<words.length(); i++ ){
        for( string& word:words){
            if( word.length() == 0 )
                continue;
            if( solve(word, 0) )
                ans.push_back(word);
            appear[word] = 1;
            //cout<<word<<endl;
        }
        return ans;
    }
    
    int solve(string& word, int len){
        int size = word.size();
        if( len == size ) return 1;
        if( len > size ) return 0;
        
        for( int i = size - 1; i >= len; --i){
            if( appear[word.substr(len, i - len+1)] ){
                //cout<<"appear "<< word.substr(len, i - len+1)<<endl;
                if( solve( word, i+1 ) ){
                    return 1;
                }
            }
        }
        return 0;
    }
};
```
      