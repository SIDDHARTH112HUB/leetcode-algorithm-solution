//Link: https://leetcode.com/problems/matchsticks-to-square/ 
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int size = nums.size();
        if( size == 0 ) return false;
        //cout<<sum<<endl;
        if( sum % 4 != 0 ) return false;
        int side_len = sum/4;
        sort(nums.begin(), nums.end(), greater<int>());
        cout<<endl;
        int cnt = 0;
        for( int i =0; i<size; i++){
            if( nums[i]>side_len )
                return false;
            vector<int> res;
            if( nums[i] > 0 ){
                bool res= solve(side_len, i, nums);
                if( res == false){
                    return false;
                }else{
                    cnt++;
                }
            }
        }
        return cnt == 4;
    }
    bool solve(int len, int i, vector<int>& nums){
        if( len == 0) return true;
        int size = nums.size();
        if( i >= size ) return false;
        if( len < 0 ) return false;
        
        bool res = solve(len-nums[i], i+1, nums);
        if( res == true)
            nums[i] = 0;
        if( res == false)
            res = solve(len, i+1, nums);
        
        return res;
    }
};