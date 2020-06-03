//Link: https://leetcode.com/problems/additive-number/ 
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for( int i = 1; i<num.size() && i < 20; i++){
            for( int j = i+1; j<num.size()&& j-i <20; j++ ){
                if( solve(num, i, j) )
                    return true;
            }
        }
        return false;
    }
    
    bool solve(string &num, int i, int j){
        long long a = stoll(num.substr(0, i));
        //int len = i;
        if( a > 0 && num[0] == '0' )
            return false;
        //cout<<num.substr(i, j-i)<<endl;
        long long b = stoll(num.substr(i, j-i));
        if( b > 0 && num[i] =='0')
            return false;
        long long c = a+b;
        string str = to_string(c);
        //cout<<"begin"<<a<<" "<<b<<" "<<str<<endl;
        while( j+str.size() <= num.size()){
            //cout<<a<<" "<<b<<" "<<str<<endl;
            //if( num[j] == '0') return false;
            if( str == num.substr(j, str.size()) ){
                if( j + str.size() == num.size() )
                    return true;
                i = j;
                j += str.size();
                a = b;
                b = c;
                c=a+b;
                str = to_string(a+b);
            }else
                return false;
            
        }
        return false;
    }
};