//Link: https://leetcode.com/problems/range-sum-query-mutable/ 
struct STree{
    STree *left = NULL;
    STree *right = NULL;
    int l = 0;
    int r = 0;
    int sum = 0;
    STree(int num, int l, int r){sum = num;this->l = l; this->r = r;}
    
    static STree* build(vector<int> &nums, int l, int r) {
        if(l > r) return NULL;
        auto root = new STree(nums[l], l, r);
        if(l == r) {
           return root;
        }
        root->left = build(nums, l, (l+r)/2);
        root->right = build(nums, (l+r)/2 + 1, r);
        root->sum = root->left?root->left->sum : 0 + root->right ? root->right->sum : 0;
        root->l = l;
        root->r = r;
        return root;
    }
    int update(int i, int num) {
        if(i == this->l && i ==this->r ) {
            this->sum = num;
            return num;
        }
        if(i < l || i > r) return this->sum;
        int sum1 = this->left ? this->left->update(i, num) : 0;
        int sum2 = this->right ? this->right->update(i, num) :0;
        this->sum = sum1 + sum2;
        return this->sum;
    }
    int query(int i, int j) {
        if(this->l > j || this->r < i )return 0;
        if(i <= this->l && j >= this->r ) return this->sum;
        int sum1 = this->left ? this->left->query(i, j) : 0;
        int sum2 = this->right? this->right->query(i, j) :0;
        return sum1 + sum2;
    }
};
struct ST {
    vector<int> arr;
    int n = 1;
    ST(){}
    void init(int _n){
        while(n < _n) n *= 2;
        arr.resize(2 * n);
    }
    void update(int idx, int num) {
        idx += n - 1;
        int diff = num - arr[idx];
        arr[idx] += diff;
        while(idx > 0) {
            idx = (idx - 1) / 2;
            arr[idx] += diff;
        }
    }
    int query(int a, int b, int k, int l, int r) {
        if(a > r || b < l) return 0;
        if(a <= l && b >= r) return arr[k];
        int lv = query(a, b, k * 2 + 1, l, (l+r) / 2);
        int rv = query(a, b, k * 2 + 2, (l+r)/2 + 1, r);
        return lv + rv;
    }
};

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
class NumArray {
public:
    BIT bit;
    ST st;
    STree *stree;
    vector<int> nums;
    NumArray(vector<int>& ns) {
        nums = ns;
        bit.init(ns.size());
        st.init(ns.size());
        stree = STree::build(nums, 0, nums.size()-1);
        for(int i = 0; i < nums.size(); ++i){
            bit.update(i, nums[i]);
            st.update(i, nums[i]);
            stree->update(i, nums[i]);
        }
        
        
    }
    
    void update(int i, int val) {
        bit.update(i, val-nums[i]);
        //bit.update(i, val);
        st.update(i, val);
        stree->update(i, val);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        //return stree->query(i, j);
        //return st.query(i, j, 0, 0, st.n-1);
        return bit.query(j) - bit.query(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */