//Link: https://leetcode.com/problems/fibonacci-number/ 
class Solution {
public:
    int fib(int N) {
        int a = 0;
        int b = 1;
        int c = 1;
        while(N-- > 0){
            c += b;
            a = b;
            b = c - b;
        }
        return a;
    }
};