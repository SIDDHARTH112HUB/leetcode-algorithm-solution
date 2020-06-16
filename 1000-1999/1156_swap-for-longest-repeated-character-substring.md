[1156.swap-for-longest-repeated-character-substring](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/)  

Given a string `text`, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.

**Example 1:**

  
**Input:** text = "ababa"
  
**Output:** 3
  
**Explanation:** We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.
  

**Example 2:**

  
**Input:** text = "aaabaaa"
  
**Output:** 6
  
**Explanation:** Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.
  

**Example 3:**

  
**Input:** text = "aaabbaaa"
  
**Output:** 4
  

**Example 4:**

  
**Input:** text = "aaaaa"
  
**Output:** 5
  
**Explanation:** No need to swap, longest repeated character substring is "aaaaa", length is 5.
  

**Example 5:**

  
**Input:** text = "abcdef"
  
**Output:** 1
  

**Constraints:**

*   `1 <= text.length <= 20000`
*   `text` consist of lowercase English characters only.  



**Solution:**  

```cpp
class Solution {
public:
    int maxRepOpt1(string text) {
        /*cout<<f("babababa",'a')<<endl;
        cout<<f("aabba",'a')<<endl;
        cout<<f("aabaaa",'a')<<endl;
        cout<<f("aabbaaba",'a')<<endl;
        cout<<f("bbaabaaba",'a')<<endl;
        cout<<f("bbaabaaba",'a')<<endl;
        cout<<f("aaaa",'a')<<endl;*/
        text.push_back(' ');
        int ans = 0;
        for(char c = 'a'; c <= 'z'; ++c)
            ans = max(ans, f(text, c));
        return ans;
    }
    
    int f(string &text, char c) {
        int last = 0;
        int total = 0;
        int first = INT_MAX;
        for(int i = 0; i < text.size(); ++i){
            if(text[i] == c) {
                ++total;
                if(first == INT_MAX)
                    first = i;
            }
        }
        if(total == 0) return 0;
        int prev = first;
        int ans = 0;
        int mid = 0;
        int i = first+1;
        bool change = false;
        for(i = first+1; i < text.size(); ++i){
            if(text[i] == c) {
                if(prev == -1)
                    prev = i;
            }else{
                
                int j = i;
                while(j < text.size() && text[j] != c){
                    ++j;
                }
                
                if(j == text.size()){
                    ans = max(ans, i - prev + 1);
                    break;
                }
                
                while(text[i+1] == c)
                    ++i;
                ans = max(ans, i - prev + 1);
                prev = j;
                /*
                if( change == false){
                    mid = i;
                    change = true;
                    if(total > i - prev + 1)
                        ans = max(ans, i - prev + 1);
                    else
                        return total;
                }
                else{
                    ans = max(ans, i - prev);
                    change = false;
                    prev = -1;
                }*/
            }
        }
        return min(total, max(ans, i - prev));
    }
};
```
      