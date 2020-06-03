//Link: https://leetcode.com/problems/perfect-number/ 
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0) return false;
        int res = 0;
        for(int i = 1; i <= sqrt(num); ++i) {
            if(!(num % i)) {
                int div = num / i;
                if(i != num)
                    res += i;
                if(i * i != num && div != num)
                    res += div;
            }
        }
        return res == num;
    }
};