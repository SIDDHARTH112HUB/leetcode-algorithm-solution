[1095.find-in-mountain-array](https://leetcode.com/problems/find-in-mountain-array/)  

_(This problem is an **interactive problem**.)_

You may recall that an array `A` is a _mountain array_ if and only if:

*   `A.length >= 3`
*   There exists some `i` with `0 < i < A.length - 1` such that:
    *   `A[0] < A[1] < ... A[i-1] < A[i]`
    *   `A[i] > A[i+1] > ... > A[A.length - 1]`

Given a mountain array `mountainArr`, return the **minimum** `index` such that `mountainArr.get(index) == target`.  If such an `index` doesn't exist, return `-1`.

**You can't access the mountain array directly.**  You may only access the array using a `MountainArray` interface:

*   `MountainArray.get(k)` returns the element of the array at index `k` (0-indexed).
*   `MountainArray.length()` returns the length of the array.

Submissions making more than `100` calls to `MountainArray.get` will be judged _Wrong Answer_.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

**Example 1:**

**Input:** array = \[1,2,3,4,5,3,1\], target = 3
**Output:** 2
**Explanation:** 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

**Example 2:**

**Input:** array = \[0,1,2,4,2,1\], target = 3
**Output:** -1
**Explanation:** 3 does not exist in `the array,` so we return -1.

**Constraints:**

*   `3 <= mountain_arr.length() <= 10000`
*   `0 <= target <= 10^9`
*   `0 <= mountain_arr.get(index) <= 10^9`  



**Solution:**  

```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    unordered_map<int, int> memo;
    int get(MountainArray &m, int idx) {
        if(memo.count(idx)) return memo[idx];
        memo[idx] = m.get(idx);
        return memo[idx];
    }
    int findInMountainArray(int target, MountainArray &m) {
        int len = m.length();
        int l = 0, r = len -1, peak = 0;
        while(l < r) {
            int mid = (l+r)/2;
            int h = get(m, mid);
            int hn = get(m, mid+1);
            if (h < hn)
                l = mid + 1;
            else
                r = mid;
        }
        peak = l;
        r = peak;
        l = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            int h = get(m, mid);
            if(h == target)
                return mid;
            else if(h < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = peak;
        r = len - 1;
        while(l <= r) {
            int mid = (l+r)/2;
            int h = get(m, mid);
            if(h == target)
                return mid;
            else if(h < target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
```
      