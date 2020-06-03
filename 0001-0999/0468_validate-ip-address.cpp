//Link: https://leetcode.com/problems/validate-ip-address/ 
class Solution {
public:
    string validIPAddress(string IP) {
        if( IP.size() < 7 ) return "Neither";
        bool is4 = true, is6 = true;
        int v4Part = 0, v6Part = 0;
        int prev = 0;
        for( char c : IP ){
            if( c == '.')
                is6 = false;
            else if( c == ':')
                is4 = false;
        }
        if( !is6 && !is4 )
            return "Neither";
        IP+= is4?".":":";
        //cout<<IP<<endl;
        for( int i = 0; i<IP.size(); i++){
            char c = IP[i];
            if( c == '.' || c == ':'){
                if( c == '.'){
                    is6 = false;
                    if( i-prev>3 || (i-prev>1 && IP[prev] == '0') || i == prev )
                        is4 = false;
                    if( is4 ){
                        int part = stoi(IP.substr(prev, i-prev));
                        if( part > 255 )
                            is4 = false;
                    }
                    prev = i+1;
                    v4Part++;
                }else{
                    is4 = false;
                    if( i-prev>4 || i == prev )
                        is6 = false;
                    prev = i+1;
                    v6Part++;
                }
                
            }else{
                if( c > '9' || c < '0' ){
                    is4 = false;
                    if(!( (c >= 'A' && c <='F') || (c>='a' && c <= 'f')))
                        is6 =false;
                }
                
            }
            if( !is4 && !is6)
                return "Neither";
        }
        if( is4 && v4Part == 4 )
            return "IPv4";
        if( is6 && v6Part == 8 )
            return "IPv6";
        return "Neither";
    }
};