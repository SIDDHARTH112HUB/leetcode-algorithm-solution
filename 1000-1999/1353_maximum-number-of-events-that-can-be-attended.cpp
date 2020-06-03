//Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/ 
struct BIT{
    vector<int> nums;
    BIT(){}
    void init(int size){
        nums.resize(size+1);
        for(int i = 1; i <= size; ++i) {
            update(i, 1);
        }
    }
    BIT(int size) : nums(size+1){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        //x++;
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        if(x < 0) return 0;
        //++x;
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
    
    int h(int l, int r) {
        while(l < r) {
            int mid = (l + r) / 2;
            int res = query(mid) - (l > 0 ? query(l-1) : 0);
            if(res > 0) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        int cnt = query(l) - (l > 0 ? query(l -1) : 0);
        return cnt > 0 ? l : -1;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int ans = 0;
        BIT bit;
        bit.init(events.back()[1]);
        for(auto &e : events) {
            int l = e[0];
            int r = e[1];
            int idx = bit.h(l, r);
            if(idx > 0) {
                ++ans;
                bit.update(idx, -1);
            }
        }
        return ans;
    }
};