//Link: https://leetcode.com/problems/summary-ranges/ 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        bool flag = false;
        int begin = 0;
        int cur = 0;
        vector< string> res;
        if( nums.size() == 0 ) return res;
        for( auto it = nums.begin(); it != nums.end(); it++ ){
            if( flag == false ){
                begin = *it;
                cur = *it;
                flag = true;
            }
            else{
                if( *it > cur+1){
                    res.push_back(getStr(begin,cur));
                    begin = *it;
                    cur = *it;
                }else{
                    cur = *it;
                }
            }
        }
        if( flag  == true)
            res.push_back(getStr(begin,cur));
        return res;
    }
    string getStr( int begin, int cur ){
        char t[100];
        if( begin == cur )
            sprintf(t, "%d", begin);
        else
            sprintf(t, "%d->%d", begin, cur);
        string a(t);
        return a;
    }
};