//Link: https://leetcode.com/problems/k-empty-slots/ 
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloom;
        bloom.insert(flowers[0]);
        for( int i = 1; i<flowers.size(); i++){
            int plot = flowers[i];
            bloom.insert(plot);
            auto it = bloom.find(plot);
            if( it!=bloom.begin() ){
                if( plot - *(--it) == k+1 )
                    return i+1;
                else
                    ++it;
            }
            if( (++it)!=bloom.end() )
                if( (*it) - plot == k + 1 )
                    return i+1;
        }
        return -1;
    }
};