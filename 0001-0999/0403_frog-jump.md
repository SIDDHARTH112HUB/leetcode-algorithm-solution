[403.frog-jump](https://leetcode.com/problems/frog-jump/)  

A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was _k_ units, then its next jump must be either _k_ - 1, _k_, or _k_ + 1 units. Note that the frog can only jump in the forward direction.

**Note:**

*   The number of stones is ≥ 2 and is < 1,100.
*   Each stone's position will be a non-negative integer < 231.
*   The first stone's position is always 0.

**Example 1:**

  
**\[0,1,3,5,6,8,12,17\]**
  

  
There are a total of 8 stones.
  
The first stone at the 0th unit, second stone at the 1st unit,
  
third stone at the 3rd unit, and so on...
  
The last stone at the 17th unit.
  

  
**Return true**. The frog can jump to the last stone by jumping 
  
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
  
2 units to the 4th stone, then 3 units to the 6th stone, 
  
4 units to the 7th stone, and 5 units to the 8th stone.
  

**Example 2:**

  
**\[0,1,2,3,4,8,9,11\]**
  

  
**Return false**. There is no way to jump to the last stone as 
  
the gap between the 5th and 6th stone is too large.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, set<int> > dp;
    int last_step;
    bool canCross(vector<int>& stones) {
        if( stones.size() <= 1 ){
            if( stones[0] != 0 ) return false;
            if( stones[1] != 1 ) return false;
            return true;
        }
        
        int num = 0;
        for( auto n: stones ){
            dp[n] = set<int>();
        }
        dp[1].insert(1);
        for( int i = 1; i<stones.size(); i++){
            num = stones[i];
            for(auto n:dp[num]){
                if( dp.find(n+1+num) != dp.end() ){
                    dp[n+1+num].insert(n+1);
                }
                if(n-1>0 && dp.find(num+n-1) != dp.end()){
                    dp[num+n-1].insert(n-1);
                }
                if(n>0 && dp.find(num+n) != dp.end()){
                    dp[num+n].insert(n);
                }
            }
        }
        return dp[num].size()>0;
    }
    
    bool canCross(vector<int>& stones) {
        
    }
    
    void dfs( vector<int> &stones, int idx, int step){
    }
};
```
      