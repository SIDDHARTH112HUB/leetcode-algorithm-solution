[295.find-median-from-data-stream](https://leetcode.com/problems/find-median-from-data-stream/)  

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,

`[2,3,4]`, the median is `3`

`[2,3]`, the median is `(2 + 3) / 2 = 2.5`

Design a data structure that supports the following two operations:

*   void addNum(int num) - Add a integer number from the data stream to the data structure.
*   double findMedian() - Return the median of all elements so far.

**Example:**

  
addNum(1)
  
addNum(2)
  
findMedian() -> 1.5
  
addNum(3) 
  
findMedian() -> 2
  

**Follow up:**

1.  If all integer numbers from the stream are between 0 and 100, how would you optimize it?
2.  If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?  



**Solution:**  

```cpp
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
```
      