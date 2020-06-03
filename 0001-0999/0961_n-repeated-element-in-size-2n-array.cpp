//Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/ 
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size() /2;
        unordered_map<int, int> m;
        for( auto num: A ){
            ++m[num];
            if( m[num] == n )
                return num;
        }
        return -1;
    }
};