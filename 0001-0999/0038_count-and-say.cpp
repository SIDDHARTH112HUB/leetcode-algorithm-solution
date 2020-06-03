//Link: https://leetcode.com/problems/count-and-say/ 
class Solution {
public:
    string countAndSay(int n) {
        if( n == 1) return "1";
        if( n == 2 ) return "11";
        string say = "11";
        char num[15];
        string tmp;
        char c;
        int array_c[10];
        for( int i = 3; i<=n; i++)
        {
            c = 0;
            tmp.clear();
            memset(array_c, 0, sizeof(int)*10);
            for( string::iterator is=say.begin();is!=say.end();++is )
            {
                char x = *is;
                if( c != x)
                {
                    if( c > 0 )
                    {
                        sprintf(num, "%d", array_c[c-'0']);
                        tmp+=num;
                        tmp+=c;
                    }
                    c=x;
                    array_c[x-'0'] = 1;
                }
                else
                    array_c[x-'0']++;
            }
            sprintf(num, "%d", array_c[c-'0']);
            tmp+=num;
            tmp+=c;
            say = tmp;
        }
        return say;
    }
};