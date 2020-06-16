[228.summary-ranges](https://leetcode.com/problems/summary-ranges/)  

Given a sorted integer array without duplicates, return the summary of its ranges.

**Example 1:**

  
**Input:**  \[0,1,2,4,5,7\]
  
**Output:** \["0->2","4->5","7"\]
  
**Explanation:** 0,1,2 form a continuous range; 4,5 form a continuous range.
  

**Example 2:**

  
**Input:**  \[0,2,3,4,6,8,9\]
  
**Output:** \["0","2->4","6","8->9"\]
  
**Explanation:** 2,3,4 form a continuous range; 8,9 form a continuous range.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        bool flag = false;
        int begin = 0;
        int cur = 0;
        vector< string> res;
        if( nums.size() == 0 ) return res;
        for( auto it = nums.begin(); it != nums.end(); it++ ){
            if( flag == false ){
                begin = *it;
                cur = *it;
                flag = true;
            }
            else{
                if( *it > cur+1){
                    res.push_back(getStr(begin,cur));
                    begin = *it;
                    cur = *it;
                }else{
                    cur = *it;
                }
            }
        }
        if( flag  == true)
            res.push_back(getStr(begin,cur));
        return res;
    }
    string getStr( int begin, int cur ){
        char t[100];
        if( begin == cur )
            sprintf(t, "%d", begin);
        else
            sprintf(t, "%d->%d", begin, cur);
        string a(t);
        return a;
    }
};
```
      