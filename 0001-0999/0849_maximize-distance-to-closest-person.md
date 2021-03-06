[849.maximize-distance-to-closest-person](https://leetcode.com/problems/maximize-distance-to-closest-person/)  

In a row of `seats`, `1` represents a person sitting in that seat, and `0` represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

**Example 1:**

  
**Input:** \[1,0,0,0,1,0,1\]  
**Output:** 2  
**Explanation: **  
If Alex sits in the second open seat (seats\[2\]), then the closest person has distance 2.  
If Alex sits in any other open seat, the closest person has distance 1.  
Thus, the maximum distance to the closest person is 2.

**Example 2:**

  
**Input:** \[1,0,0,0\]  
**Output:** 3  
**Explanation: **  
If Alex sits in the last seat, the closest person is 3 seats away.  
This is the maximum distance possible, so the answer is 3.  

**Constraints:**

*   `2 <= seats.length <= 20000`
*   `seats` contains only 0s or 1s, at least one `0`, and at least one `1`.  



**Solution:**  

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = -1, r=-1;
        int ans = 0;
        for( int i = 0; i<seats.size(); i++){
            if( seats[i] == 0){
                l = min(i, l);
                r = max(i, r);
            }
            else{
                if( l == -1 )
                    ans = i;
                else{
                    ans = max((r-l+1)/2, ans);
                }
                l = i;
                r = i;
            }
        }
        if( seats[seats.size()-1]==0 ){
            ans = max(r-l, ans);
        }
        return ans;
    }
};
```
      