//Link: https://leetcode.com/problems/zigzag-conversion/ 
class Solution {
public:
    string convert(string s, int nRows) {
        if( nRows <= 1) return s;
        string res="";
        int len = s.length();
        if( len <= 1 ) return s;
        int step = (nRows-1)*2;
        for( int i = 0; i<nRows; i++)
        {
            int cnt = 0;
            do
            {
                int idx = i + step*cnt;
                int idx2= i + step*cnt + (nRows-i%nRows-1)*2;
                if( idx < len)
                    res += s.at(idx);
                else
                    break;
                if(idx2<len && i!=0 && i!=(nRows-1))
                    res += s.at(idx2);
                ++cnt;
                    
            }while(true);
        }
        return res;
    }
};