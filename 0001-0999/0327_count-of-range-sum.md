[327.count-of-range-sum](https://leetcode.com/problems/count-of-range-sum/)  

Given an integer array `nums`, return the number of range sums that lie in `[lower, upper]` inclusive.  
Range sum `S(i, j)` is defined as the sum of the elements in `nums` between indices `i` and `j` (`i` ≤ `j`), inclusive.

**Note:**  
A naive algorithm of _O_(_n_2) is trivial. You MUST do better than that.

**Example:**

**Input:** _nums_ = `[-2,5,-1]`, _lower_ = `-2`, _upper_ = `2`,
**Output:** 3 
**Explanation:** The three ranges are : `[0,0]`, `[2,2]`, `[0,2]` and their respective sums are: `-2, -1, 2`.  



**Solution:**  

```cpp
class Solution {
public:
    
     int countRangeSum(vector<int> &nums, int lower, int upper) {
        // write your code here
        map<long long, long long > m;
        m[0] = 1;
        long long sum = 0;
        int ans = 0;
        for( int i = 0; i< nums.size(); i++){
            long long n = nums[i];
            sum += n;
            
            auto b = m.lower_bound(sum-upper);
            auto e = m.upper_bound(sum-lower);
            while( b != e && b != m.end() ){
                ans += b->second;
                ++b;
            }
            ++m[sum];
            
        }
        return ans;
    }
};
```
      