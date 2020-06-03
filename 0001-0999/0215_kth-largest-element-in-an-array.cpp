//Link: https://leetcode.com/problems/kth-largest-element-in-an-array/ 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //auto mptr = nums.begin() + nums.size()-k;
        //nth_element(nums.begin(), mptr, nums.end());
        //return *mptr;
        int l = 0, r = nums.size()-1;
        while(true){
            int pos = partition(nums, l, r);
            if( pos == k-1) return nums[pos];
            else if( pos >k-1) r = pos-1;
            else l = pos+1;
        }
        return -1;
    }
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int left = l;
        l=l+1;
        while(l<=r){
            if( nums[l] < pivot && nums[r] >pivot){
                swap(nums[l++], nums[r--]);
            }
            if( nums[l] >= pivot )++l;
            if( nums[r] <= pivot)--r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};