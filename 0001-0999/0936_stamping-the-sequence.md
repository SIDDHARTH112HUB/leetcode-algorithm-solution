[936.stamping-the-sequence](https://leetcode.com/problems/stamping-the-sequence/)  

You want to form a `target` string of **lowercase letters**.

At the beginning, your sequence is `target.length` `'?'` marks.  You also have a `stamp` of lowercase letters.

On each turn, you may place the stamp over the sequence, and replace every letter in the sequence with the corresponding letter from the stamp.  You can make up to `10 * target.length` turns.

For example, if the initial sequence is "?????", and your stamp is `"abc"`,  then you may make "abc??", "?abc?", "??abc" in the first turn.  (Note that the stamp must be fully contained in the boundaries of the sequence in order to stamp.)

If the sequence is possible to stamp, then return an array of the index of the left-most letter being stamped at each turn.  If the sequence is not possible to stamp, return an empty array.

For example, if the sequence is "ababc", and the stamp is `"abc"`, then we could return the answer `[0, 2]`, corresponding to the moves "?????" -> "abc??" -> "ababc".

Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within `10 * target.length` moves.  Any answers specifying more than this number of moves will not be accepted.

**Example 1:**

  
**Input:** stamp = "abc", target = "ababc"
  
**Output:** \[0,2\]
  
(\[1,0,2\] would also be accepted as an answer, as well as some other answers.)
  

**Example 2:**

  
**Input:** stamp = "abca", target = "aabcaca"
  
**Output:** \[3,0,1\]
  

**Note:**

1.  `1 <= stamp.length <= target.length <= 1000`
2.  `stamp` and `target` only contain lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int total = 0;
        unordered_set<int> v;
        while( total < target.size() ){
            bool found = false;
            for( int i = 0; i <= target.size()-stamp.size(); i++){
                int l = unstamp(stamp, target, i);
                if( l == 0 ) continue;
                if( v.count(i) ) continue;
                total += l;
                v.insert(i);
                ans.push_back(i);
                found = true;
                for( int k = 0; k< stamp.size(); k++ )
                    target[k+i] = '*';
            }
            if( !found ) return {};
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int unstamp(string &stamp, string &target, int idx){
        int l = 0;
        for( int i = 0; i < stamp.size(); i++){
            if( target[i+idx] == '*') 
                continue;
            if(target[i+idx] == stamp[i]){
                l++;
            }else{
                return 0;
            }
        }
        return l;
    }
};
```
      