//Link: https://leetcode.com/problems/reconstruct-itinerary/ 
class Solution {
public:
    map<string, multiset<string> > data;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for( auto &p:tickets){
            data[p.first].insert(p.second);
        }
        
        vector<string> itinerary;
        dfs("JFK", itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
    void dfs(string ticket, vector<string> &itinerary){
        auto &edge = data[ticket];
        while(edge.size()){
            string t = *edge.begin();
            edge.erase(edge.begin());
            dfs(t, itinerary);
        }
        itinerary.push_back(ticket);
    }
};