//Link: https://leetcode.com/problems/design-hit-counter/ 
class HitCounter {
public:
    deque<int> dq;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        dq.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        while(dq.size() && dq.front() + 300 <= timestamp) dq.pop_front();
        return dq.size();
    }
};
