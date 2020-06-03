//Link: https://leetcode.com/problems/bulb-switcher-iii/ 
struct BIT{
    vector<int> nums;
    BIT(){}
    void init(int size){
        nums.resize(size+1);
    }
    BIT(int size) : nums(size+1){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        x++;
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        if(x < 0) return 0;
        ++x;
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        BIT bit;
        bit.init(light.size() + 2);
        int ans = 0;
        int mx = 0;
        for(int i = 0; i < light.size(); ++i) {
            int idx = light[i];
            mx = max(mx, idx);
            bit.update(idx, 1);
            if(bit.query(mx) ==  mx)
                ++ans;
        }
        return ans;
    }
};