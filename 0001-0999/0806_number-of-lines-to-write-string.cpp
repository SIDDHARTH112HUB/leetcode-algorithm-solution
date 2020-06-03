//Link: https://leetcode.com/problems/number-of-lines-to-write-string/ 
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1;
        int num  = 0;
        vector<int> ans;
        for( char c : S ){
            int width = widths[c-'a'];
            if( num + width > 100 ){
                num = width;
                line++;
            }else{
                num += width;
            }
        }
        ans.push_back(line);
        ans.push_back(num);
        return ans;
    }
};