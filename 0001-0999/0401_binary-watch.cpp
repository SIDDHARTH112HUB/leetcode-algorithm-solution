//Link: https://leetcode.com/problems/binary-watch/ 
class Solution {
public:
    //vector<string> m;
    //vector<string> s;
    int count1(int num){
        int cnt = 0;
        while(num > 0){
            cnt += (num%2);
            num = num >> 1;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for( int i = 0; i<=3; i++){
            int j = num - i;
            if( j < 0 || j > 5)
                continue;
            for( int m = 0; m<=11; m++){
                if( count1(m) == i){
                    for( int s = 0; s<=59; s++){
                        if( count1(s) == j){
                            string sec_str = to_string(s);
                            if(sec_str.size() == 1)
                                sec_str = "0"+sec_str;
                            ans.push_back(to_string(m)+":"+sec_str);
                        }
                    }
                }
            }
        }
        return ans;
    }
};