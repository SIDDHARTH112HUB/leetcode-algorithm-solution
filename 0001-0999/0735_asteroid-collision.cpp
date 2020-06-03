//Link: https://leetcode.com/problems/asteroid-collision/ 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(auto ast : asteroids) {
            if(ast > 0) stk.push_back(ast);
            else {
                while(stk.size() && stk.back() > 0 && stk.back() < -ast) 
                    stk.pop_back();
                if(stk.size() == 0 || stk.back() < 0)
                    stk.push_back(ast);
                else if(stk.back() == -ast)
                    stk.pop_back();
            }
        }
        return stk;
    }
};