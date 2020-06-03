//Link: https://leetcode.com/problems/swap-adjacent-in-lr-string/ 
class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0, j=0;
        while(i<start.size() || j < end.size() ){
            while(i < start.size() && start[i] == 'X')i++;
            while(j < end.size() && end[j] == 'X')j++;
            if( i == start.size() || j == end.size() )
                return i == j;
            if( start[i] != end[j] ) return false;
            else if( start[i] == 'L' && j > i )return false;
            else if( start[i] == 'R' && i > j) return false;
            i++;j++;
        }
        return true;
    }
};