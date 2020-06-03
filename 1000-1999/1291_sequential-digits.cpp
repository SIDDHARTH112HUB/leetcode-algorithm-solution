//Link: https://leetcode.com/problems/sequential-digits/ 
class Solution {
public:
    int l;
    int r;
    vector<int> sequentialDigits(int low, int high) {
        l = low, r = high;
        vector<int> ans;
        for(int i = 1; i <= 8; ++i) {
            int n = i;
            int c = i;
            while(n < low && c <= 9) {
                //if(c > 9) break;
                n = n * 10 + (++c);
            }
            //cout<<n<<" c:"<<c<<endl;
            while(n <= high && n >= low && c <= 9) {
                ans.push_back(n);
                n = n * 10 + (++c);
                if( c > 9)break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
};