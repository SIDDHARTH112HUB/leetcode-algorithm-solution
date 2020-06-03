//Link: https://leetcode.com/problems/analyze-user-website-visit-pattern/ 
class Solution {
public:
    unordered_map<string, vector<pair<int, string> > > uservisit;
    unordered_map<string, unordered_set<string> > seqCnt;
    int maxCnt = 0;
    string ans;
    vector<string> vans;
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        for(int i = 0; i < username.size(); ++i) {
            
            uservisit[username[i]].push_back({timestamp[i], website[i]});
        }
        for(auto it : uservisit){
            sort(it.second.begin(), it.second.end());
            vector<string> item;
            auto seq = it.second;
            auto un = it.first;
            helper(seq, un, 0, item);
        }
        return vans;
    }
    
    void helper(vector<pair<int, string> > &seq, string &user, int idx, vector<string> &item) {
        if(item.size() == 3) {
            string str = item[0] + "," + item[1] + "," + item[2];
            seqCnt[str].insert(user);
            int c = seqCnt[str].size();
            if(c > maxCnt) {
                //cout<<"count: "<<str<<endl;
                ans = str;
                vans = item;
                maxCnt =c;
            }else if( c == maxCnt) {
                if(ans > str || ans == ""){
                    ans = str;
                    vans = item;
                }
            }
            return;
        }
        for(int i = idx; i < seq.size(); ++i) {
            item.push_back(seq[i].second);
            helper(seq, user, i + 1, item);
            item.pop_back();
        }
    }
};