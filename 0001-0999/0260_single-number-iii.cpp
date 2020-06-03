//Link: https://leetcode.com/problems/single-number-iii/ 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> vec;
        if( nums.size() == 0 )
            return vec;
        int x = 0;
        for( auto iter = nums.begin(); iter!= nums.end(); iter++){
            x ^= (*iter);
        }
        
        int last = x & ( ~(x - 1) );
        int a = 0;
        int b = 0;
        for( auto iter = nums.begin(); iter!= nums.end(); iter++){
            if( (last & (*iter)) == 0 ){
                a ^= (*iter);
            }
            else{
                b ^= (*iter);
            }
        }
        vec.push_back(a);
        vec.push_back(b);
        return vec;
    }
};