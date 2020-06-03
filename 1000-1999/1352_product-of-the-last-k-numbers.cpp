//Link: https://leetcode.com/problems/product-of-the-last-k-numbers/ 
class ProductOfNumbers {
public:
    vector<long long> v;
    int mx = 0;
    int p = 0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(v.size() && v.back() > 0) {
            v.push_back(v.back() * num);
        }else {
            v.push_back(num);
        }
        if(num == 0)
            mx = v.size();
    }
    
    int getProduct(int k) {
        if(v.size() - k < mx) return 0;
        if(v.size() <= k) return v.back();
        if(v[v.size() - k - 1] == 0) return v.back();
        return v.back() / v[v.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */