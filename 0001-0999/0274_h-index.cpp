//Link: https://leetcode.com/problems/h-index/ 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        for( int i = 0; i<citations.size(); i++){
            if( citations[i]>=size-i)
                return size-i;
        }
        return 0;
    }
};