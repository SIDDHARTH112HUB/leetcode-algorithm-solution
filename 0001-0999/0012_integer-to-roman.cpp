//Link: https://leetcode.com/problems/integer-to-roman/ 
class Solution {
public:
    string intToRoman(int num) {
        char *b1[9]= { "I","II","III","IV","V","VI","VII","VIII","IX"  };
        char *b2[9]= { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"  };
        char *b3[9]= { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"  };
        char *b4[9]= { "M","MM","MMM","","","","","",""  };
    
        char **b[4]={b4, b3, b2, b1};
        int bit = 0;
        int s = 1000;
        string res = "";
        while( s > 0)
        {
            int a = num / s;
            if( a > 0 )
                res.append(b[bit][a-1]);
            bit++;
            num = num % s;
            s /= 10;
        }
        return res;
    }
};