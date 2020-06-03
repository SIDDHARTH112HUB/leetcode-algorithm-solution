//Link: https://leetcode.com/problems/moving-average-from-data-stream/ 
class MovingAverage {
public:
    /** Initialize your data structure here. */
    deque<int> dq;
    int sum = 0;
    int size = 0;
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        dq.push_back(val);
        sum += val;
        if(dq.size() > size) {
            sum -= dq.front();dq.pop_front();
        }
        return sum * 1.0/ dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */