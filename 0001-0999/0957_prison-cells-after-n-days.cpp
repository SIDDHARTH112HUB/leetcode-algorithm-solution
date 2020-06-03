//Link: https://leetcode.com/problems/prison-cells-after-n-days/ 
class Solution {
public:
    string cellFormat(vector<int> &cells){
        string ans;
        for( int cell: cells)
            ans += '0' + cell;
        return ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map< string, int > m;
        string cellStr = cellFormat( cells ), prev;
        vector<int> ans;
        while( m.count(cellStr) == 0 ){
            if( m.size() == N ){
                for( auto c : cellStr)
                    ans.push_back(c-'0');
                return ans;
            }
            prev = cellStr;
            m[cellStr] = m.size();
            string nc = cellStr;
            nc[0] = '0';
            nc[7] = '0';
            for( int i = 1; i < 7; i++){
                nc[i] = (cellStr[i-1] == cellStr[i+1]) ? '1':'0';
            }
            cellStr = nc;
        }
        
        int day = (N - m.size()) % (m[prev] - m[cellStr]+1);
        for( auto it: m){
            if( it.second - m[cellStr] == day){
                for( auto c: it.first)
                    ans.push_back(c-'0');
                return ans;
            }
        }
        return {};
    }
};
