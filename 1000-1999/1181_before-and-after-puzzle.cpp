//Link: https://leetcode.com/problems/before-and-after-puzzle/ 
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<pair<string, int> > > last, first;
        for(int k = 0; k < phrases.size(); ++k) {
            string str = phrases[k];
            //cout<<"str: "<<str<<endl;
            str += ' ';
            for(int i = 0; i < str.size(); ++i) {
                if(str[i] == ' ' || i == str.size() - 1) {
                    string s1 = str.substr(0, i);
                    string s2 = str.substr(i + 1, str.size() - 1);
                    first[s1].push_back({s2, k});
                    //cout<<"first "<<s1<<endl;
                    break;
                }
            }
            str.pop_back();
            str = " " + str;
            for(int i = str.size()-1; i >= 0; --i) {
                if(str[i] == ' ' || i == 0) {
                    string s1 = str.substr(i+1); 
                    string s2 = str.substr(1);
                    last[s1].push_back({s2, k});
                    //cout<<"last "<<s1<<endl;
                    break;
                }
            }
        }
        set<string> ans;
        for(auto &it : last) {
            string str = it.first;
            for(auto &p : it.second) {
                int i1 = p.second;
                string &l = p.first;
                for(auto &p2 : first[str]){
                    int i2 = p2.second;
                    if(i1 == i2) continue;
                    string &r = p2.first;
                    string res = l + " " + r;
                    if(res.back() == ' ')
                        res.pop_back();
                    //if(res == "")
                    //    res = str;
                    ans.insert(res);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};