//Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/ 
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        for( int i = 0; i<deck.size(); i++)
            dq.push_back(i);
        vector<int> vec;
        sort(deck.begin(), deck.end());
        while( dq.size() ){
            vec.push_back(dq.front());
            dq.pop_front();
            if( dq.size() ){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        vector<int> ans(deck.size());
        for( int i = 0; i<vec.size(); i++){
            ans[vec[i]] = deck[i];
        }
        return ans;
    }
};