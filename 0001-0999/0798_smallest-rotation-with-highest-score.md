[798.smallest-rotation-with-highest-score](https://leetcode.com/problems/smallest-rotation-with-highest-score/)  

 Given an array `A`, we may rotate it by a non-negative integer `K` so that the array becomes `A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], A[1], ..., A[K-1]`.  Afterward, any entries that are less than or equal to their index are worth 1 point. 

For example, if we have `[2, 4, 1, 3, 0]`, and we rotate by `K = 2`, it becomes `[1, 3, 0, 2, 4]`.  This is worth 3 points because 1 > 0 \[no points\], 3 > 1 \[no points\], 0 <= 2 \[one point\], 2 <= 3 \[one point\], 4 <= 4 \[one point\].

Over all possible rotations, return the rotation index K that corresponds to the highest score we could receive.  If there are multiple answers, return the smallest such index K.

**Example 1:**
**Input:** \[2, 3, 1, 4, 0\]
**Output:** 3
**Explanation: ** 
Scores for each K are listed below: 
K = 0,  A = \[2,3,1,4,0\],    score 2
K = 1,  A = \[3,1,4,0,2\],    score 3
K = 2,  A = \[1,4,0,2,3\],    score 3
K = 3,  A = \[4,0,2,3,1\],    score 4
K = 4,  A = \[0,2,3,1,4\],    score 3

So we should choose K = 3, which has the highest score.

**Example 2:**
**Input:** \[1, 3, 0, 2, 4\]
**Output:** 0
**Explanation: ** A will always have 3 points no matter how it shifts.
So we will choose the smallest K, which is 0.

**Note:**

*   `A` will have length at most `20000`.
*   `A[i]` will be in the range `[0, A.length]`.  



**Solution:**  

```cpp
struct BIT {
    vector<int> arr;
    int base = 0;
    BIT(int size) {
        arr.resize((size+1) * 3);
        base = size * 2;
    };
    int low(int x) {return x & -x;}
    void update(int x, int cnt) {
        x += base;
        while(x < arr.size()) {
            arr[x] += cnt;
            x += low(x);
        }
    }
    int query(int x) {
        x += base;
        int sum = 0;
        while(x > 0) {
            sum += arr[x];
            x -= low(x);
        }
        return sum;
    }
};
class Solution {
public:
    int bestRotation(vector<int>& A) {
        BIT bit(A.size()+1);
        int size = A.size();
        for(int i = 0; i < A.size(); ++i) {
            int sum = A[i] - i;
            bit.update(sum, 1);
        }
        int ans = bit.query(0);
        int idx = 0;
        for(int i = 1; i < A.size(); ++i) {
            int sum = A[i-1] - (i - 1);
            bit.update(sum, -1);
            sum -= A.size();
            bit.update(sum, 1);
            int n = bit.query(-i);
            if(n > ans) {
                idx = i;
                ans = n;
            }
            //cout<<n<<endl;
        }
        return idx;
    }
};
```
      