//Link: https://leetcode.com/problems/global-and-local-inversions/ 
struct BIT{
    vector<int> arr;
    BIT(int n){
        arr.resize(n);
    }
    int lowbit(int x) { return x & -x;}
    void update(int num, int x){
        while(num < arr.size()) {
            arr[num] += x;
            num += lowbit(num);
        }
    }
    int query(int num) {
        int sum = 0;
        while(num > 0) {
            sum += arr[num];
            num -= lowbit(num);
        }
        return sum;
    }
};
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        //vector<pair<int, int> > a;
        int g = 0, l = 0;
        BIT bit(A.size() + 1);
        for(int i = A.size()-1; i >= 0; --i){
            bit.update(A[i] + 1, 1);
            g += bit.query(A[i]);
            if(i > 0 && A[i] < A[i-1])
                ++l;
                
        }
        return g == l;
        
    }
};