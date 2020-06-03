//Link: https://leetcode.com/problems/excel-sheet-column-number/ 
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        long long sum = 0;
        for( int i = 0; i<len ; i++)
        {
            char a = s.at(i);
            int num = a-'A'+1;
            sum += num*pow(26, len-i-1);
        }
        return sum;
    }
};