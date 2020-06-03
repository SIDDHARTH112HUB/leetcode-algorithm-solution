//Link: https://leetcode.com/problems/roman-to-integer/ 
class Solution {
public:
    int romanToInt(string s) {
        if( s.size() == 0 ) return 0;
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int sum = 0;
        for( int i = 0; i<s.size(); ++i){
            int num1 = dict[s[i]];
            if( i == s.size()-1){
                sum += num1;
                break;
            }
            int num2 = dict[s[i+1]];
            if( num1 < num2)
                sum -= num1;
            else
                sum += num1;
        }
        return sum;
    }
};