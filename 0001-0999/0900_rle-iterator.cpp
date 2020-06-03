//Link: https://leetcode.com/problems/rle-iterator/ 
class RLEIterator {
public:
    vector<int> data;
    int cur;
    RLEIterator(vector<int> A) {
        cur = 0;
        data = A;
    }
    
    int next(int n) {
        if( data.size() <= cur ) return -1;
        while( data.size() > cur ){
            int &count = data[cur];
            
            if( count > n ){
                count -= n;
                return data[cur+1];
            }else{
                n -= count;
                cur+=2;
                if( n == 0 )
                    return data[cur-1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */