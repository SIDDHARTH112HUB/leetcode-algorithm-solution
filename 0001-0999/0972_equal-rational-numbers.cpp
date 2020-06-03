//Link: https://leetcode.com/problems/equal-rational-numbers/ 
class Solution {
public:
    void helper(string S, int &ip, string &r){
        bool flag = true, loop = false;
        string loopstr;
        bool zeroR = true;
        for( int i = 0; i< S.size(); i++ ) {
            if( S[i] == '.'){
                flag = false;
                continue;
            }else if( S[i] =='('){
                loop = true;
                continue;
            }else if( S[i] == ')')
                break;
            if( flag == true){
                ip = ip * 10 + S[i]-'0';
            }else{
                if( S[i] -'0' > 0 )
                    zeroR = false;
                if( loop == true){
                    loopstr+= S[i];
                }else{
                    r += S[i];
                }
            }
        }
        int zero = 0, nine = 0;
        for( auto c : loopstr){
            if( c== '0')
                zero++;
            else if( c=='9')
                nine++;
        }
        if( zero > 0 && zero == loopstr.size() )
            loopstr = "";
        if( nine > 0 && nine == loopstr.size() ){
            int c = 0;
            for( int i = int(r.size())-1; i>=0; i--){
                if( r[i] == '9'){
                    r[i] = '0';
                }else{
                    r[i] += 1;
                    break;
                }
                    
            }
            zero = 0;
            for( auto c : r )
                if( c == '0')
                    zero++;
            if( zero == r.size() ){
                r = "";
                ++ip;
            }
            loopstr = "";
        }
        for( int i = 0; i< 20; i++)
            r += loopstr;
        if( zeroR == true )
            r = "";
    }
    bool isRationalEqual(string S, string T) {
        int ip1 = 0, ip2=0;
        string r1, r2;
        helper(S, ip1, r1);
        helper(T, ip2, r2);
        r1 = r1.substr(0, min((int)r1.size(), 20));
        r2 = r2.substr(0, min((int)r2.size(), 20));
        //cout<<ip1<<"."<<r1<<" "<<ip2<<"."<<r2<<endl;
        /*if( ip1 != ip2 || r1 != r2 ){
            if( abs(ip1-ip2) > 1 ) return false;
            if( r1 == "99999999999999999999"){
                ip1++;
                r1 = "";
            }
            if(r2 == "99999999999999999999"){
                ip2++;
                r2 = "";
            }
        }
        */
        return ip1 == ip2 && r1 == r2;
    }
};