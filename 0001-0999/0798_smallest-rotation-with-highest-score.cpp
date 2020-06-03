//Link: https://leetcode.com/problems/smallest-rotation-with-highest-score/ 
struct BIT {
    vector<int> arr;
    int base = 0;
    BIT(int size) {
        arr.resize((size+1) * 3);
        base = size * 2;
    };
    int low(int x) {return x & -x;}
    void update(int x, int cnt) {
        x += base;
        while(x < arr.size()) {
            arr[x] += cnt;
            x += low(x);
        }
    }
    int query(int x) {
        x += base;
        int sum = 0;
        while(x > 0) {
            sum += arr[x];
            x -= low(x);
        }
        return sum;
    }
};
class Solution {
public:
    int bestRotation(vector<int>& A) {
        BIT bit(A.size()+1);
        int size = A.size();
        for(int i = 0; i < A.size(); ++i) {
            int sum = A[i] - i;
            bit.update(sum, 1);
        }
        int ans = bit.query(0);
        int idx = 0;
        for(int i = 1; i < A.size(); ++i) {
            int sum = A[i-1] - (i - 1);
            bit.update(sum, -1);
            sum -= A.size();
            bit.update(sum, 1);
            int n = bit.query(-i);
            if(n > ans) {
                idx = i;
                ans = n;
            }
            //cout<<n<<endl;
        }
        return idx;
    }
};