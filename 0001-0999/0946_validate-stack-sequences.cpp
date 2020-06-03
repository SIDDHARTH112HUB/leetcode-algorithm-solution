//Link: https://leetcode.com/problems/validate-stack-sequences/ 
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        reverse(popped.begin(), popped.end());
        stack<int> stk;
        //set<int> m;
        for( int n : pushed ){
            stk.push(n);
            while( stk.size() && popped.size() && stk.top() == popped.back() ){
                stk.pop();
                popped.pop_back();
            }
            
        }
        return stk.size() == 0 && popped.size() == 0;
    }
};