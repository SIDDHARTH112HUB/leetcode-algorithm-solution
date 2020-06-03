//Link: https://leetcode.com/problems/exclusive-time-of-functions/ 
class Solution {
public:
    vector<int> ans;
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        ans.resize(n);
        int i = 0;
        while(i < logs.size()) {
            h(logs, i);
        }
        return ans;
    }
    
    int h( vector<string>& logs, int &idx) {
        int start = -1, id = -1;
        int sum = 0;
        while(idx < logs.size()){
            stringstream ss(logs[idx]);
            string token;
            vector<string> logArr;
            while(getline(ss, token, ':')) {
                logArr.push_back(token);
            }
            if(logArr[1] == "start") {
                if(start != -1) {
                    sum += h(logs, idx);
                }else{
                    start = stoi(logArr[2]);
                    id = stoi(logArr[0]);
                    ++idx;
                }
            }else{
                ++idx;
                int end = stoi(logArr[2]);
                int total = end - start - sum + 1;
                ans[id] += total;
                return end - start + 1;
            }
        }
        return 0;
    }
};