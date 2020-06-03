//Link: https://leetcode.com/problems/valid-number/ 
class Solution {
public:
    bool isNumber(string str) {
        int i = str.find_first_not_of(' ');
        if( str[i] == '+' || str[i] == '-' )
            i++;
        int dot = 0;
        int num = 0;
        int e = 0;
        long long cur_num = 0;
        while( (str[i] >='0' && str[i] <='9') || str[i] == '.' || str[i]=='e'){
            if( str[i] == '.' ){
                if( e > dot )
                    return false;
                dot++;
            }
            else if( str[i] == 'e' ){
                e++;
                if( str[i+1] =='+' ||str[i+1] == '-' ){
                    i++;
                }
                if(str[i+1] < '0' || str[i+1] >'9')
                    return false;
            }
            else{
                num++;
            }
            if( e>num || e>1)
                return false;
            if( dot > 1 )
                return false;
            
            i++;
        }
        
        if( num == 0 ) return false;
        while(str[i] == ' ')i++;
        return i  == str.size();
    }
};