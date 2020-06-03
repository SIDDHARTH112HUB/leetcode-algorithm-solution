//Link: https://leetcode.com/problems/median-of-two-sorted-arrays/ 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int m = nums2.size();
        if( m > n ) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = m;
        while( l <= r ){
            int partX = (l + r)/2;
            int partY = (m + n + 1)/2 - partX;
            
            int leftX = (partX == 0 ? INT_MIN : nums2[partX-1]);
            int rightX= (partX == m ? INT_MAX : nums2[partX]);
            int leftY = (partY == 0 ? INT_MIN : nums1[partY-1]);
            int rightY= (partY == n ? INT_MAX : nums1[partY]);
            if( leftX <= rightY && rightX >= leftY){
                if( (m + n)  % 2 == 0 )
                    return (max(leftX, leftY) + min(rightX, rightY )) /2.0;
                else 
                    return max( leftX, leftY);
            }else if( leftX > rightY ){
                r = partX - 1;
            }else{
                l = partX + 1;
            }
        }
        return -1;
    }
};