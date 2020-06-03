//Link: https://leetcode.com/problems/find-median-from-data-stream/ 
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int> > minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);
        if(maxpq.size() > minpq.size()) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }else{
            minpq.push(maxpq.top());
            maxpq.pop();
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        double res = minpq.top();
        if((maxpq.size() + minpq.size()) % 2== 0){
            res += maxpq.top();
            return res/2;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */