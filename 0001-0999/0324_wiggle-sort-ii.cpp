//Link: https://leetcode.com/problems/wiggle-sort-ii/ 
class Solution {
public:
    
    void wiggleSort(vector<int>& nums) {
        
        int size = nums.size();
        if( size <= 1) return;
        auto mptr = nums.begin() + (size-1)/2;
        nth_element(nums.begin(), mptr, nums.end());
        int mid = *mptr;
        int i = 1;
        int j = ((size-1) & 1) ? size-2:size-1;
        //cout<<mid<<endl;
        for( int k=0; k<size; ++k){
            if( nums[k] > mid && i <size ){
                if( k <= i && (k & 1 ) ) continue;
                swap(nums[k--], nums[i]);
                i += 2;
            }else if( nums[k] < mid && j>=0 ){
                if( k >= j && (k & 1 ) == 0 ) continue;
                swap(nums[k--], nums[j]);
                j -= 2;
            }
        }
    }
};