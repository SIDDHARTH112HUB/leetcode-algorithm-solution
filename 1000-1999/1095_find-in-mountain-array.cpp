//Link: https://leetcode.com/problems/find-in-mountain-array/ 
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