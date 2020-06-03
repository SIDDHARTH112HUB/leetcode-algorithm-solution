//Link: https://leetcode.com/problems/my-calendar-ii/ 
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int, int> m;
    bool book(int start, int end) {
        int cnt = 0;
        m[start] += 1;
        m[end] -= 1;
        for( auto it:m){
            cnt += it.second;
            if( cnt >= 3 ){
                m[start] -= 1;
                m[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */