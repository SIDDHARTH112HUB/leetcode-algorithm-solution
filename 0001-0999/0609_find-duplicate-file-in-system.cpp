//Link: https://leetcode.com/problems/find-duplicate-file-in-system/ 
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > ans;
        
        for( auto &path : paths ){
            string cur_path, filename;
            int file_name_begin = 0, content_begin=0;
            for( int i = 0; i < path.size(); i++ ){
                char c = path[i];
                if( c == ' '){
                    if( cur_path == "" ){
                        cur_path = path.substr(0, i);
                    }
                    file_name_begin = i+1;
                    continue;
                }
                else if( c == '('){
                    filename = path.substr(file_name_begin, i-file_name_begin);
                    content_begin = i+1;
                }
                else if( c == ')'){
                    
                    string content = path.substr(content_begin, i-content_begin);
                    m[content].push_back(cur_path+"/"+filename);
                }
            }
        }
        for( auto &it: m){
            if( it.second.size() > 1 )
                ans.push_back(it.second);
        }
        return ans;
    }
};