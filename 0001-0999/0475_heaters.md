[475.heaters](https://leetcode.com/problems/heaters/)  

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

**Note:**

1.  Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
2.  Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
3.  As long as a house is in the heaters' warm radius range, it can be warmed.
4.  All the heaters follow your radius standard and the warm radius will the same.

**Example 1:**

  
**Input:** \[1,2,3\],\[2\]
  
**Output:** 1
  
**Explanation:** The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
  

**Example 2:**

  
**Input:** \[1,2,3,4\],\[1,4\]
  
**Output:** 1
  
**Explanation:** The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.  



**Solution:**  

```cpp
class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int j = 0, res = 0, n = heaters.size();
        for(int house : houses) {
            int idx = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int d1 = idx == n ? INT_MAX : heaters[idx] - house ;
            int d2 = idx == 0 ? INT_MAX : house - heaters[idx-1];
            res = max(res, min(d1, d2));
        }
        return res;
    }
    /*
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int j = 0, res = 0;
        for(int house : houses) {
            while(j < heaters.size()-1 && abs(house - heaters[j]) >= abs(house-heaters[j+1]) ) {
                ++j;
            }
            res = max(res, abs(house - heaters[j]));
        }
        return res;
    }*/
};
```
      