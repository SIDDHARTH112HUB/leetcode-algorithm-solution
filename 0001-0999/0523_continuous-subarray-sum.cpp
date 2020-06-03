//Link: https://leetcode.com/problems/continuous-subarray-sum/ 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int size = nums.size();
        if( size <= 1 ) return false;
        
            for( int i = 1; i<nums.size(); i++){
                if( nums[i-1] == 0 && nums[i] == 0)
                    return true;
                
            }
        if( k == 0 ){
            return false;
        }
        int sum = 0;
        if( k < 0 ) k *= -1;
        //cout<<k<<endl;
        m[0] = 1;
        for( int i = 0; i<nums.size(); i++){
            sum += nums[i];
            //if( nums[i] % k == 0 )continue;
            //if( sum % k == 0 && i > 0 ) return true;
            if( m[sum % k] > 0 && m[sum%k] -2 <= i-2){
                //if( i - m[sum % k]+1 >= 2 )
                //    return true;
                //else
                //    m[sum%k] = i+1;
                return true;
            }
            if( m[sum%k] == 0 ){
                m[sum%k] = i+2;
            }
        }
        cout<<sum<<endl;
        return false;
    }
};