//Link: https://leetcode.com/problems/simplify-path/ 
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        char str[10240];
        strcpy(str, path.c_str());
        const char* token = strtok(str, "/");
        vector<string> vec;
        if( token != NULL){
            do{
                int len = strlen(token);
                if( len > 0 ){
                    if( strcmp(token, "..") == 0){
                        if( vec.size()>0)
                            vec.pop_back();
                    }
                    else if (strcmp(token, ".") != 0){
                        vec.push_back(token);
                    }
                }
            }while( (token=strtok(NULL, "/")) );
        }
        string res = "/";
        for( int i = 0; i<vec.size(); i++){
            string& s = vec[i];
            res.append(s);
            res.append("/");
        }
        if( vec.size()>0)
            res[res.length()-1] = 0;
        return res;
    }
};