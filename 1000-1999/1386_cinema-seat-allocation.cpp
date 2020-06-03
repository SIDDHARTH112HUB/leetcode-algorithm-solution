//Link: https://leetcode.com/problems/cinema-seat-allocation/ 
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        map<int, map<int, int> > g;
        for(auto &s : reservedSeats) {
            g[s[0]][1] = 1;
            g[s[0]][s[1]] = 1;
            g[s[0]][10] = 1;
        }
        //cout<<"begin"<<endl;
        int prev = 0;
        for(auto it : g) {
            int cur = it.first;
            ans += (cur - prev - 1) * 2;
            //cout<<cur<<" "<<prev<<endl;
            int p2 = 0;
            for(auto it2 : it.second) {
                int c2 = it2.first;
                if(p2 == 1 && c2 == 10)
                    ans += 2;
                else if(p2 == 1 && c2 >=6)
                    ans += 1;
                else if(p2 <= 3 && c2 >= 8)
                    ans += 1;
                else if(p2 <= 5 && c2 == 10)
                    ans += 1;
                p2 = c2;
            }
            prev = cur;
        }
        ans += (n - prev) * 2;
        return ans;
    }
};


