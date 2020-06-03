//Link: https://leetcode.com/problems/regular-expression-matching/ 
class Solution {
public:
    bool match( char* s, char*  p){
        //if( *s=='\0' ) return *p!='.';
        if(*p =='\0') return *s=='\0';
        //printf("%s %s \n", s,p);
        if( p[1] == '*' )
            return match_star(p[0], p+2, s );
        if( *s !=  '\0' && ( *s == *p || *p=='.' )){
            return match(++s, ++p);
        }
        return 0;
    }
    bool match_star(char c, char* p, char* s){
        do{
            if( match(s, p) )
                return 1;
        }while( *s != '\0' && (*s++ == c || c == '.'));
        return 0;
    }
    bool isMatch(string s, string p) {
        
        //if( s.length() == 0 ) return 0;
        //if( p.length() == 0 ) return 0;
        char* cs = (char*)s.c_str();
        char* cp = (char*)p.c_str();
        do{
            if( this->match( cs, cp ) )
                return 1;
            //cs++;
        }while(false);
        return 0;
    }
};