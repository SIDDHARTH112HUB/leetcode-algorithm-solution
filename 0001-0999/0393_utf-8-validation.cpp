//Link: https://leetcode.com/problems/utf-8-validation/ 
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        int i = 0;
        while(i < data.size()) {
            if(cnt > 0) {
                if((data[i] >> 6) != 2) return false;
                --cnt;
            }else {
                int num = data[i];
                while(num & 0x80) {
                    ++cnt;
                    num = num << 1;
                }
                if(cnt == 1 || cnt >= 5) return false;
                if(cnt > 1) --cnt;
            }
            ++i;
        }
        return cnt == 0;
    }
};