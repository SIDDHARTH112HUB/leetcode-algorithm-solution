//Link: https://leetcode.com/problems/moving-stones-until-consecutive/ 
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int mn = 0, mx = 0;
        vector<int> v = {a,b, c};
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        if(c - a == 2 ) mn = 0;
        else if(c -b <= 2 || b -a <= 2) mn = 1;
        else mn = 2;
        mx = c - b - 1+ b - a - 1;
        return {mn, mx};
    }
};