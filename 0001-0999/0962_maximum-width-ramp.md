[962.maximum-width-ramp](https://leetcode.com/problems/maximum-width-ramp/)  

Given an array `A` of integers, a _ramp_ is a tuple `(i, j)` for which `i < j` and `A[i] <= A[j]`.  The width of such a ramp is `j - i`.

Find the maximum width of a ramp in `A`.  If one doesn't exist, return 0.

**Example 1:**

**Input:** \[6,0,8,2,1,5\]
**Output:** 4
**Explanation:** 
The maximum width ramp is achieved at (i, j) = (1, 5): A\[1\] = 0 and A\[5\] = 5.

**Example 2:**

**Input:** \[9,8,1,0,1,9,4,0,4,1\]
**Output:** 7
**Explanation:** 
The maximum width ramp is achieved at (i, j) = (2, 9): A\[2\] = 1 and A\[9\] = 1.

**Note:**

1.  `2 <= A.length <= 50000`
2.  `0 <= A[i] <= 50000`  



**Solution:**  

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans = 0;
        vector<pair<int, int> > ramp;
        ramp.push_back({A[0], 0});
        for( int i = 1; i< A.size(); i++ ){
            int num = A[i];
            if( num >= ramp.back().first ){
                int l = 0, r = ramp.size()-1;
                int mid = l;
                while( l <= r ){
                    mid = (l + r)/2;
                    if( ramp[mid].first > num )
                        l = mid+1;
                    else{
                        if( mid > 0 ){
                            if( ramp[mid-1].first <= num)
                                r = mid-1;
                            else
                                break;
                        }else{
                            break;
                        }
                    }
                }
                if( ramp[mid].first <= num )
                    ans = max(ans, i - ramp[mid].second);
            }else{
                ramp.push_back({num, i});
            }
            
        }
        return ans;
    }
};
```
      