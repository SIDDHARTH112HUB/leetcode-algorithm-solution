//Link: https://leetcode.com/problems/online-stock-span/ 
class StockSpanner {
public:
    vector< pair<int, int> > data;
    int cur;
    StockSpanner() {
        this->cur = 0;
        data.push_back({INT_MAX, 0});
    }
    
    int next(int price) {
        this->cur++;
        while( data.size() > 0 ){
            if( data.back().first > price ){
                int res = this->cur- data.back().second;
                data.push_back({price, this->cur});
                return res;
            }else{
                data.pop_back();
            }
        }
        return -1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */