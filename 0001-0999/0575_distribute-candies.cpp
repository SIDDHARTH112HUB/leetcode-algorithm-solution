//Link: https://leetcode.com/problems/distribute-candies/ 
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> m;
        for(auto c : candies) m.insert(c);
        return min(candies.size()/2, m.size());
    }
};