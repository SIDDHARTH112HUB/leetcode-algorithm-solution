//Link: https://leetcode.com/problems/corporate-flight-bookings/ 
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<pair<int, int> > m(n+1);
        for(auto &book : bookings) {
            int i = book[0];
            int j = book[1];
            int s = book[2];
            m[i].first += s;
            m[j].second += s;
        }
        vector<int> ans(n);
        long long total = 0;
        for(int i = 1; i <= n; ++i) {
            int b = m[i].first;
            int e = m[i].second;
            total += b;
            //total += e;
            ans[i-1] += total;
            total -= e;
        }
        return ans;
    }
};