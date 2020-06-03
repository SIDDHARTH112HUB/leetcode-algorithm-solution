//Link: https://leetcode.com/problems/design-a-leaderboard/ 
class Leaderboard {
public:
    Leaderboard() {
        sc.resize(10010);
    }
    vector<int> sc;
    void addScore(int playerId, int score) {
        sc[playerId] += score;
    }
    
    int top(int K) {
        auto _sc = sc;
        int sum  = 0;
        sort(_sc.begin(), _sc.end());
        for(int i = (int)sc.size() - 1; i >=0; --i) {
            if(K == 0) break;
            --K;
            sum += _sc[i];
        }
        return sum;
    }
    
    void reset(int playerId) {
        sc[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */