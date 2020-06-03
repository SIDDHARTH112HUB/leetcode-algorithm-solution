//Link: https://leetcode.com/problems/apply-discount-every-n-orders/ 
class Cashier {
public:
    map<int, int> p;
    int discount = 0;
    int n;
    int cnt = 1;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->discount = discount;
        for(int i = 0; i < products.size(); ++i) {
            p[products[i]] = prices[i];
        }
        this->n = n;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double dis = cnt % n == 0 ? (1 - discount/100.0) : 1.0;
        double sum = 0;
        for(int i = 0; i < product.size(); ++i) {
            sum += p[product[i]] * amount[i];
        }
        ++cnt;
        return sum *= dis;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */