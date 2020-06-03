//Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 
class Solution {
public:
    void combine(vector<string>& ans, string& digits, int idx, char* item){
        if( digits[idx] == '\0' ){
            item[idx] = '\0';
            ans.push_back(item);
            return;
        }
        static char* letter_arr[10] = {
            "","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        char* letter_str = (char*)letter_arr[digits[idx]-'0'];
        while(*letter_str !='\0'){
            item[idx] = *letter_str;
            this->combine(ans, digits, idx+1,item);
            letter_str++;
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if( digits.size() == 0 ) return ans;
        char ans_item[100];
        this->combine(ans, digits, 0, ans_item);
        return ans;
    }
};