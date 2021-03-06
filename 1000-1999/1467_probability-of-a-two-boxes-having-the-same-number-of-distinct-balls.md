[1467.probability-of-a-two-boxes-having-the-same-number-of-distinct-balls](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)  

Given `2n` balls of `k` distinct colors. You will be given an integer array `balls` of size `k` where `balls[i]` is the number of balls of color `i`. 

All the balls will be **shuffled uniformly at random**, then we will distribute the first `n` balls to the first box and the remaining `n` balls to the other box (Please read the explanation of the second example carefully).

Please note that the two boxes are considered different. For example, if we have two balls of colors `a` and `b`, and two boxes `[]` and `()`, then the distribution `[a] (b)` is considered different than the distribution `[b] (a)` (Please read the explanation of the first example carefully).

We want to _calculate the probability_ that the two boxes have the same number of distinct balls.

**Example 1:**

  
**Input:** balls = \[1,1\]  
**Output:** 1.00000  
**Explanation:** Only 2 ways to divide the balls equally:  
- A ball of color 1 to box 1 and a ball of color 2 to box 2  
- A ball of color 2 to box 1 and a ball of color 1 to box 2  
In both ways, the number of distinct colors in each box is equal. The probability is 2/2 = 1  

**Example 2:**

  
**Input:** balls = \[2,1,1\]  
**Output:** 0.66667  
**Explanation:** We have the set of balls \[1, 1, 2, 3\]  
This set of balls will be shuffled randomly and we may have one of the 12 distinct shuffles with equale probability (i.e. 1/12):  
\[1,1 / 2,3\], \[1,1 / 3,2\], \[1,2 / 1,3\], \[1,2 / 3,1\], \[1,3 / 1,2\], \[1,3 / 2,1\], \[2,1 / 1,3\], \[2,1 / 3,1\], \[2,3 / 1,1\], \[3,1 / 1,2\], \[3,1 / 2,1\], \[3,2 / 1,1\]  
After that we add the first two balls to the first box and the second two balls to the second box.  
We can see that 8 of these 12 possible random distributions have the same number of distinct colors of balls in each box.  
Probability is 8/12 = 0.66667  

**Example 3:**

  
**Input:** balls = \[1,2,1,2\]  
**Output:** 0.60000  
**Explanation:** The set of balls is \[1, 2, 2, 3, 4, 4\]. It is hard to display all the 180 possible random shuffles of this set but it is easy to check that 108 of them will have the same number of distinct colors in each box.  
Probability = 108 / 180 = 0.6  

**Example 4:**

  
**Input:** balls = \[3,2,1\]  
**Output:** 0.30000  
**Explanation:** The set of balls is \[1, 1, 1, 2, 2, 3\]. It is hard to display all the 60 possible random shuffles of this set but it is easy to check that 18 of them will have the same number of distinct colors in each box.  
Probability = 18 / 60 = 0.3  

**Example 5:**

  
**Input:** balls = \[6,6,6,6,6,6\]  
**Output:** 0.90327  

**Constraints:**

*   `1 <= balls.length <= 8`
*   `1 <= balls[i] <= 6`
*   `sum(balls)` is even.
*   Answers within `10^-5` of the actual value will be accepted as correct.  



**Solution:**  

```cpp

#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
class Solution {
public:
    vector<vector<double> > pascal;
    int half = 0;
    int sum = 0;
    double getProbability(vector<int>& balls) {
        pascal.resize(49, vector<double>(49));
        pascal[0][0] = 1;
        sum = accumulate(balls.begin(), balls.end(), 0);
        half = sum/2;
        for(int i = 1; i < pascal.size(); ++i) {
            pascal[i][0] = 1;
            for(int j = 1; j <= i; ++j) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        vector<int> leftArr(balls.size()), rightArr(balls.size());
        return dfs(balls, 0, leftArr, rightArr, 0, 0) / combination(balls);
    }
    double combination(vector<int> &nums) {
        int sum = acc(nums);
        double p = 1;
        for(auto n : nums) {
            p *= pascal[sum][n];
            sum -= n;
        }
        return p;
    }
    double dfs(vector<int>& balls, int idx, vector<int>& leftArr, vector<int>& rightArr, int left, int right) {
        if(left > half || right > half) return 0;
        if(idx >= balls.size()) {
            int c1 = 0, c2 = 0;
            for(auto n : leftArr) c1 += n> 0;
            for(auto n : rightArr) c2 += n> 0;
            if(c1 != c2) return 0;
            return combination(leftArr) * combination(rightArr);
        }
        double res = 0;
        for(int i = 0; i <= balls[idx]; ++i) {
            leftArr[idx] = i;
            rightArr[idx] = balls[idx] - i;
            res += dfs(balls, idx + 1, leftArr, rightArr, left + i, right + balls[idx] - i);
        }
        return res;
    }
};
```
      