//Link: https://leetcode.com/problems/baseball-game/ 
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        int sum = 0;
        for(auto op : ops) {
            if(op == "+") {
                int score = stk.back() +stk[stk.size() -2]; 
                sum += score;
                stk.push_back(score);
            }else if(op == "C") {
                sum -= stk.back(); stk.pop_back();
            }else if(op == "D") {
                sum += stk.back() * 2;
                stk.push_back(stk.back() * 2);
            }else {
                int score = stoi(op);
                sum += score;
                stk.push_back(score);
            }
        }
        return sum;
    }
};
