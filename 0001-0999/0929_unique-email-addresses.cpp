//Link: https://leetcode.com/problems/unique-email-addresses/ 
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> m;
        for( string &email : emails){
            string real_email = "";
            bool isAddr = false;
            for( int i = 0; i<email.size(); i++){
                char c = email[i];
                
                if( isAddr == true ){
                    real_email+= c;
                    continue;
                }
                if( c == '.')
                    continue;
                else if( c == '+'){
                    
                    while( c != '@'){
                        c = email[++i];
                    }
                    real_email+='@';
                    isAddr = true;
                    continue;
                }
                real_email+= c;
            }
            m[real_email] = 1;
        }
        return m.size();
    }
};