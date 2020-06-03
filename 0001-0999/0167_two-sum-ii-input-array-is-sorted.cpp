//Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> dict;
        for( int i = 0; i<numbers.size(); i++){
            if( dict[target-numbers[i]] > 0 ){
                return {dict[target-numbers[i]], i+1};
            }
            dict[numbers[i]] = i+1;
        }
        return {};
    }
};