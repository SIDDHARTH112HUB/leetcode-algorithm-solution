[346.moving-average-from-data-stream](https://leetcode.com/problems/moving-average-from-data-stream/)  

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

**Example:**

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3  



**Solution:**  

```cpp
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
```
      