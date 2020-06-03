//Link: https://leetcode.com/problems/unique-word-abbreviation/ 
class ValidWordAbbr {
public:
    map<string, string> m;
    string abbr(string &d) {
        if(d.size() <= 2) return d;
        return d.substr(0, 1) + to_string(d.size() - 2) + d.substr(d.size() - 1);
    }
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto d : dictionary) {
            string ab  =abbr(d);
            if(m.count(ab) && m[ab] != d){
                m[ab] = "";
            }else
                m[ab] = d;
        }
    }
    
    bool isUnique(string word) {
        string ab = abbr(word);
        return m.count(ab) == 0 || m[ab] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */