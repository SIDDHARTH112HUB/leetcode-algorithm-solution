[128.longest-consecutive-sequence](https://leetcode.com/problems/longest-consecutive-sequence/)  

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(_n_) complexity.

**Example:**

**Input:** \[100, 4, 200, 1, 3, 2\]
**Output:** 4
**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.  



**Solution:**  

```cpp
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s(num.begin(), num.end());
        int ans = 0;
        for(int low : s ){
            if( s.find(low-1) == s.end()){
                int hight = low+1;
                while( s.find(hight) != s.end() ){
                    hight++;
                }
                ans = max(ans, hight - low);
            }
        }
        return ans;
    }
    /*
    int longestConsecutive(vector<int> &num) {
        map<int, int> hm;
        for(int i = 0; i < num.size(); i++)
        {
            hm[num[i]] = i;
        }
        int seq_num = 0,max=0;
        for(int i = 0; i < num.size(); i++)
        {
            int v = num[i];
            int vs = v;
            seq_num = 0;
            do
            {
                map<int, int>::iterator iter = hm.find(v);
                if( iter == hm.end())
                    break;
                
                hm.erase(iter);
                
                ++seq_num;
                ++v;
            }while(true);
            --vs;
            do
            {
                map<int, int>::iterator iter = hm.find(vs);
                if( iter == hm.end())
                    break;
                hm.erase(iter);
                ++seq_num;
                --vs;
            }while(true);
            
            if( seq_num > max )
                max=seq_num;
        }
        return max;
    }*/
};
```
      