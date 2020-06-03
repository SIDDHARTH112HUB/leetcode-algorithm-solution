//Link: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/ 
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 100000;
        while(l < r) {
            int mid = (l + r) / 2;
            int num = reader.get(mid);
            if(num >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        return reader.get(l) == target ? l : -1;
    }
};