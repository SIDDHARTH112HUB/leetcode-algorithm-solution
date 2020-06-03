//Link: https://leetcode.com/problems/self-dividing-numbers/ 
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int num = left; num<=right; num++){
            if( num <= 0 )
                continue;
            int n = num;
            while(n>0){
                if( n % 10 == 0 )
                    break;
                int m = n % 10;
                if( num % m == 0 )
                    n = n / 10;
                else
                    break;
            }
            if( n == 0 )
                ans.push_back(num);
        }
        return ans;
    }
};