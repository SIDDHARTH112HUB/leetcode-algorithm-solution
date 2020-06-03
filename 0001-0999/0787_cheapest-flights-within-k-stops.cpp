//Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/ 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, unordered_map<int, int> > m;
        for( auto &flight : flights ){
            m[flight[0]][flight[1]] = flight[2];
        }
        queue< vector<int> > pq;
        pq.push({0, src, 0});
        unordered_map<int, int> seen;
        seen[src] = -1;
        int ans = INT_MAX;
        int k = 0;
        while( pq.size() ){
            int size = pq.size();
            while( size--> 0 ){
                int total = pq.front()[0];
                int src = pq.front()[1];
                int k = pq.front()[2];

                pq.pop();
                if(k > K )
                    continue;
                for( auto it: m[src]){
                    int des = it.first;
                    int price = it.second;
                    if( des == dst )
                        ans = min(ans, total + price);
                    else{
                        if( seen[des] == 0 || seen[des] > total + price  ){
                            pq.push({total + price, des, k+1});
                            seen[des] = total + price;
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};