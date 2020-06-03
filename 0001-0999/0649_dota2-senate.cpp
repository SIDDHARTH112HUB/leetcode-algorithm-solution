//Link: https://leetcode.com/problems/dota2-senate/ 
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.size();
        for( int i = 0; i<senate.size(); i++){
            if( senate[i] == 'R') q1.push(i); else q2.push(i);
        }
        while( q1.size() && q2.size() ){
            int idx1 = q1.front(), idx2 = q2.front();
            q1.pop(); q2.pop();
            if( idx1 < idx2 ) q1.push(n+idx1); else q2.push(n+idx2);
        }
        return q1.size()>q2.size() ? "Radiant" : "Dire";
    }
};