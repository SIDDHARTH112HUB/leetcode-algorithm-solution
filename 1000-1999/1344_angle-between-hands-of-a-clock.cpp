//Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/ 
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = minutes / 60.0 * 360;
        double b = (hour  % 12) / 12.0 *360 + (minutes/60.0/12.0 * 360);
        //cout<<a<<" "<<b<<endl;
        double ang = fabs(a - b);
        if(ang > 180) return 360 - ang;
        return ang;
    }
};