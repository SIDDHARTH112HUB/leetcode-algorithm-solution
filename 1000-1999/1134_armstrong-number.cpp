//Link: https://leetcode.com/problems/armstrong-number/ 
class Solution {
public:
    bool isArmstrong(int N) {
        int res = 0;
        int power = 0;
        int n = N;
        while(n> 0){
            power++;
            n/=10;
        }
        n = N;
        while(n>0){
            int d = n%10;
            res += pow(d, power);
            n /= 10;
        }
        return res == N;
    }
};