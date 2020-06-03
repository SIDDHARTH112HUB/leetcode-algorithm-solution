//Link: https://leetcode.com/problems/minimum-unique-word-abbreviation/ 
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if(dictionary.size() == 0) return to_string(target.size());
        vector<string> items;
        generate(target, 0, 0, "", items);
        sort(items.begin(), items.end(), [](auto &a, auto &b){
            return a.size() < b.size();
        });
        for(auto &str : items) {
            bool res = true;
            for(auto &d : dictionary) {
                if(d.size() != target.size()) continue;
                if(valid(str, d)){
                    res = false;
                    break;
                }
            }
            if(res) return str;
        }
        return "";
    }
    
    bool valid(string &str, string d) {
        int j = 0;
        int size = 0;
        bool f = false;
        string nd;
        for(int i = 0; i < str.size(); ++i) {
            int c = str[i];
            if(c >= 0 && c <= '9') {
                size = size * 10 + c - '0';
                nd += c;
            }
            else {
                if(size > 0)
                    j += size;
                
                if(j >= d.size()) return false;
                nd += d[j];
                ++j;
                size = 0;
            }
        }
        return nd == str;
    }
    void generate(string &target, int i, int cnt, string str, vector<string> &items) {
        if(i >= target.size()) {
            items.push_back(str + (cnt > 0 ? to_string(cnt) : ""));
            return;
        }
        generate(target, i + 1, cnt + 1, str, items);
        generate(target, i + 1, 0, str + (cnt > 0 ? to_string(cnt) : "") + target[i], items);
    }
};