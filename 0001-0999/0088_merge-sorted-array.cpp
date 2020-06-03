//Link: https://leetcode.com/problems/merge-sorted-array/ 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0 ) return;
        int i = 0, j =0;
        auto &n1 = nums1, &n2 = nums2;
        while( i<m+n ){
            if( i>=m ){
                n1[i] = n2[j];
                j++;
            }else if( n1[i] >  n2[j]){
                swap(n1[i], n2[j]);
                for( int k = 1; k<n; k++){
                    if( n2[k-1] > n2[k])
                        swap(n2[k-1], n2[k]);
                }
            }
            i++;
        }
    }
};