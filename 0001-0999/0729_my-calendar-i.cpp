//Link: https://leetcode.com/problems/my-calendar-i/ 
class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int, int> m;
    bool book1(int start, int end) {
        auto it = m.lower_bound(end);
        if( it == m.end() ){
            if( m.size() > 0 && start < (--it)->second )
                return false;
        }else if( it != m.begin() ){
            if( (--it)->second > start )
                return false;
        }
        m[start] = end;
        return true;
    }
    bool book(int start, int end) {
        int cnt = 0;
        m[start] += 1;
        m[end] -= 1;
        for( auto it:m){
            cnt += it.second;
            if( cnt >= 2 ){
                m[start] -= 1;
                m[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */