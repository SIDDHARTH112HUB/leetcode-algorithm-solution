[332.reconstruct-itinerary](https://leetcode.com/problems/reconstruct-itinerary/)  

Given a list of airline tickets represented by pairs of departure and arrival airports `[from, to]`, reconstruct the itinerary in order. All of the tickets belong to a man who departs from `JFK`. Thus, the itinerary must begin with `JFK`.

**Note:**

1.  If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.
2.  All airports are represented by three capital letters (IATA code).
3.  You may assume all tickets form at least one valid itinerary.
4.  One must use all the tickets once and only once.

**Example 1:**

    Input: 

**Example 2:**

    Input:  



**Solution:**  

```cpp
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
```
      