//Link: https://leetcode.com/problems/super-ugly-number/ 
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        if( n <= 1 ) return n;
        int dp[n+1] = {0};
        vector<int> vidx(primes.size());
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
        
        for( int i = 0; i<primes.size(); i++){
            pq.push({primes[i], i});
        }
        dp[0] = 1;
        for( int i = 1; i<n; i++){
            pair<int, int> p = pq.top();
            dp[i] = p.first;
            int next;
            //cout<<dp[i]<<endl;
            do{
                p = pq.top();
                pq.pop();
                int &idx = vidx[p.second];
                idx++;
                if( pq.size() > 0 )
                    next = pq.top().first;
                pq.push({dp[idx]*primes[p.second],p.second});
                if(pq.size() == 1 )
                    break;
            }while(p.first == next);
        }
        return dp[n-1];
    }
};