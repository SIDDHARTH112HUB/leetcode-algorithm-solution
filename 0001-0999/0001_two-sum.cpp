//Link: https://leetcode.com/problems/two-sum/ 

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int sum){
    unordered_map<int, int> m;
    for( int i = 0; i < nums.size(); i++ ){
      int n = nums[i];
      if( m.count(sum - n) ){
        return {m[sum-n], i};
      }
      m[n] = i;
    }
    return {-1, -1};
  }

};
