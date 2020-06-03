//Link: https://leetcode.com/problems/course-schedule-iii/ 
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
            if( a[1] == b[1] )
                return a[0]<b[0];
            return a[1] < b[1];
        });
        multiset<int> dict;
        int sum = 0;
        for( auto &course:courses){
            int t = course[0];
            int end = course[1];
            if( sum + t <= end ){
                sum += t;
                dict.insert(t);
            }else if(dict.size() > 0 && *dict.rbegin() > t ){
                sum += (t - *dict.rbegin());
                dict.erase(--dict.end());
                dict.insert(t);
            }
        }
        return dict.size();
    }
};