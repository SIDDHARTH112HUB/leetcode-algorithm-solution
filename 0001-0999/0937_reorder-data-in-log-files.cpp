//Link: https://leetcode.com/problems/reorder-data-in-log-files/ 
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs, digit_logs;
        for( auto &str:logs){
            if( str.back() >= '0' && str.back() <='9' )
                digit_logs.push_back(str);
            else
                letter_logs.push_back(str);
        }
        sort(letter_logs.begin(), letter_logs.end(), [](string &a, string &b){
            int i = 0, j = 0;
            while(a[i++] !=' ');
            while(b[j++] !=' ');
            return a.substr(i) < b.substr(j);
        });
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};