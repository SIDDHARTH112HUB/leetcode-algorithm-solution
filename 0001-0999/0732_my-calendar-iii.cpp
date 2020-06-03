//Link: https://leetcode.com/problems/my-calendar-iii/ 
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int, int> m;
    int book(int start, int end) {
        m[start] += 1;
        m[end]   -= 1;
        int cnt = 0;
        int ans = 0;
        for( auto it : m){
            cnt += it.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */